# New ports collection makefile for:	libiodbc
# Date created:				24 Mar 2000
# Whom:					erikhb@bgnett.no
#
# $FreeBSD$
#
# Note:  The location of ${INIDIR} and the installed name of the "odbctest"
#        binary were chosen such that this port does not conflict with
#        databases/unixODBC.

PORTNAME=	libiodbc
PORTVERSION=	3.51.1
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://www.iodbc.org/downloads/iODBC/

MAINTAINER=	ebakke@trolltech.com
COMMENT=	An ODBC 3.x driver manager, for universal data source access

CONFLICTS=	unixODBC-*

USE_LIBTOOL_VER=	13
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
INIDIR=		${PREFIX}/etc/${PORTNAME}
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-iodbc-inidir=${INIDIR} --with-pthread
CFLAGS += -D_BSD_WCHAR_T_DEFINED_

.if !defined(WITHOUT_GUI)
USE_GNOME=	gtk12
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB+=	GUI="@comment "
.endif

post-install:
	@ ${MKDIR} ${INIDIR} && \
	  ${INSTALL_DATA} ${WRKSRC}/etc/odbc*.ini.sample ${INIDIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in AUTHORS COPYING ChangeLog NEWS README
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
