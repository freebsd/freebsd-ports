# vim: ts=8
# New ports collection makefile for:	MySQL GUI Tools
# Date created:				6 March 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	mysql-gui-tools
PORTVERSION=	5.0r12
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MySQLGUITools

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The MySQL Administrator, Query Browser and Workbench GUI tools

LIB_DEPENDS=	mysqlclient.15:${PORTSDIR}/databases/mysql50-client \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		pcre.0:${PORTSDIR}/devel/pcre \
		xml2.5:${PORTSDIR}/textproc/libxml2

OPTIONS=	QUERY_BROWSER	"Build the MySQL Query Browser"	on \
		ADMINISTRATOR	"Build the MySQL Administrator"	on

USE_GL=		gl glut
USE_GMAKE=	yes
USE_GNOME=	libglade2 gtkhtml3 libgnomeprint intlhack

DATADIR=	${PREFIX}/share/mysql-gui

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CXXFLAGS="${CFLAGS}" CPPFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}" ACLOCAL="${TRUE}" \
		AUTOMAKE="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}"
CONFIGURE_ARGS=	--with-gtkhtml=libgtkhtml-3.14 --prefix=${PREFIX}

SUBDIRS=	mysql-gui-common

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_QUERY_BROWSER)
SUBDIRS+=	mysql-query-browser
PLIST_SUB+=	QUERY_BROWSER=""
.else
PLIST_SUB+=	QUERY_BROWSER="@comment "
.endif

.if !defined(WITHOUT_ADMINISTRATOR)
SUBDIRS+=	mysql-administrator
PLIST_SUB+=	ADMINISTRATOR=""
.else
PLIST_SUB+=	ADMINISTRATOR="@comment "
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-i18n
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITHOUT_ADMINISTRATOR) && defined(WITHOUT_QUERY_BROWSER)
IGNORE=	please run 'make config' again and select at least one component
.endif

post-patch:
	${REINPLACE_CMD} -e 's|lseek64|lseek|g' \
	    ${WRKSRC}/mysql-administrator/source/linux/MInstanceInfo.cc
	${REINPLACE_CMD} -e '578s|make|${GMAKE}|g' \
	    ${WRKSRC}/mysql-query-browser/source/linux/Makefile.in
	${REINPLACE_CMD} -e 's|-ldl|-luuid|g' \
	    ${WRKSRC}/mysql-gui-common/tools/grtsh/Makefile.in \
	    ${WRKSRC}/mysql-gui-common/tools/grtsh/Makefile.am
	${REINPLACE_CMD} -e 's|-llualib||g' ${WRKSRC}/mysql-gui-common/configure \
	    ${WRKSRC}/mysql-gui-common/source/php/Makefile \
	    ${WRKSRC}/mysql-gui-common/source/php/modules/Makefile
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e \
	    	's|-DG.*_DISABLE_DEPRECATED||g'
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e '/^SUBDIRS/s|po||' \
	    ${WRKSRC}/mysql-gui-common/Makefile.am \
	    ${WRKSRC}/mysql-gui-common/Makefile.in \
	    ${WRKSRC}/mysql-administrator/Makefile.am \
	    ${WRKSRC}/mysql-administrator/Makefile.in \
	    ${WRKSRC}/mysql-query-browser/Makefile.am \
	    ${WRKSRC}/mysql-query-browser/Makefile.in
.endif

do-configure:
.for dir in ${SUBDIRS}
	(cd ${WRKSRC}/${dir} && \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} \
	)
.endfor

do-build:
.for dir in ${SUBDIRS}
	cd ${WRKSRC}/${dir} &&  ${SETENV} ${MAKE_ENV} ${GMAKE}
.endfor

do-install:
.for dir in ${SUBDIRS}
	cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}
.endfor

.include <bsd.port.post.mk>
