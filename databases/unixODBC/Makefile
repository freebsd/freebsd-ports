# New ports collection makefile for:    unixODBC
# Date created:         May 11, 2000
# Whom:                 Nick Sayer <nsayer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unixODBC
PORTVERSION=	2.2.14
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.unixodbc.org/

MAINTAINER=	cowbert@gmail.com
COMMENT=	ODBC library suite for Unix

CONFLICTS=	libiodbc-[0-9]*

USE_GNOME=	gnomehack gnometarget
USE_ICONV=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--enable-static --enable-shared \
		--with-libiconv-prefix=${LOCALBASE}
USE_LDCONFIG=	yes

PORTDOCS=	*

.if defined(WITH_GUI)
USE_QT_VER=	3
QT_NONSTANDARD=	yes
CONFIGURE_ENV=	MOC="${MOC}" \
		QTINC="${QT_PREFIX}/include" \
		QTLIB="${QT_PREFIX}/lib" \
		USER_INCLUDES="${QTCPPFLAGS}" \
		USER_LDFLAGS="${QTCFGLIBS}"
CONFIGURE_ENV+=	QTMAX=030400
CONFIGURE_ARGS+=--enable-gui
PLIST_SUB=	GUI:=""
.else
CONFIGURE_ARGS+=--disable-gui
PLIST_SUB=	GUI:="@comment "
.endif

.if !defined(WITHOUT_THREADS) || defined(WITH_GUI)
CONFIGURE_ARGS+=--enable-threads=yes
.else
CONFIGURE_ARGS+=--enable-threads=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,@MSQL_TRUE@lib_LTLIBRARIES,#&,' \
		${WRKSRC}/Drivers/MiniSQL/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude '*Makefile*' -cf - . \
		| ${TAR} -C ${DOCSDIR} --unlink -xf -
.if !defined(INSTALL_AS_USER)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${FIND} ${DOCSDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	${FIND} ${DOCSDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
.endif
.endif
.for conffile in odbc.ini odbcinst.ini
	@if [ ! -f ${PREFIX}/etc/${conffile} ]; then \
		${CP} -p ${PREFIX}/etc/${conffile}.sample ${PREFIX}/etc/${conffile} ; \
	fi
.endfor

.include <bsd.port.mk>
