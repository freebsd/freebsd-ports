# vim: ts=8
# New ports collection makefile for:	MySQL GUI Tools
# Date created:				6 March 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	mysql-gui-tools
PORTVERSION=	5.0r14
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

USE_AUTOTOOLS=	autoconf:262 libtool:15 automake:110
USE_GNOME=	gnomelibs libglade2 gtkhtml3 libgnomeprint intlhack gtksourceview
USE_GL=		gl glut
USE_GMAKE=	yes

DATADIR=	${PREFIX}/share/mysql-gui

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gtkhtml=libgtkhtml-3.14

.include <bsd.port.pre.mk>

SUBDIRS=	common

.if !defined(WITHOUT_QUERY_BROWSER)
SUBDIRS+=	query-browser
PLIST_SUB+=	QUERY_BROWSER=""
.else
PLIST_SUB+=	QUERY_BROWSER="@comment "
.endif

.if !defined(WITHOUT_ADMINISTRATOR)
SUBDIRS+=	administrator
PLIST_SUB+=	ADMINISTRATOR=""
.else
PLIST_SUB+=	ADMINISTRATOR="@comment "
.endif

.if defined(WITHOUT_ADMINISTRATOR) && defined(WITHOUT_QUERY_BROWSER) && defined(WITHOUT_MIGRATION_TOOL)
IGNORE=	please run 'make config' again and select at least one component
.endif

post-patch:
# switch to new directory name not complete
	(cd ${WRKSRC} && ${LN} -sf common mysql-gui-common)
# UTF-8 input file
	(LC_CTYPE=C ${TR} -d "\357\273\277" < \
	    ${WRKSRC}/common/library/base-library/source/myx_database_model.c > \
	    ${WRKSRC}/common/library/base-library/source/myx_database_model.c.new && \
	    ${MV} ${WRKSRC}/common/library/base-library/source/myx_database_model.c.new \
	    	${WRKSRC}/common/library/base-library/source/myx_database_model.c)

	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    ${WRKSRC}/query-browser/source/linux/Makefile.am

# Run-time paths
	${REINPLACE_CMD} -e 's|MQB_DIR="$$DIRNAME"|MQB_DIR=""|' \
	    ${WRKSRC}/query-browser/source/linux/mysql-query-browser
	${REINPLACE_CMD} -e 's|MA_DIR="$$DIRNAME"|MA_DIR=""|' \
	    ${WRKSRC}/administrator/source/linux/mysql-administrator

run-autotools:
do-configure:
.for dir in ${SUBDIRS}
	(cd ${WRKSRC}/${dir} && ${SH} autogen.sh ${CONFIGURE_ARGS} && \
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
