# New ports collection makefile for:	MyODBC
# Date created:				22 Mar 2004
# Whom:					sergey@migsoft.com.ua
#
# $FreeBSD$
#

PORTNAME=	myodbc
PORTVERSION=	3.51.06
CATEGORIES=	databases
MASTER_SITES=	http://mysql.paco.net/Downloads/MyODBC3/ \
		ftp://sunsite.dk/mirrors/mysql/Downloads/MyODBC/ \
		ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MyODBC/
DISTNAME=	MyODBC-${PORTVERSION}

MAINTAINER=	ebakke@trolltech.com
COMMENT=	ODBC driver for MySQL

USE_MYSQL=	yes

USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-mysql-libs=${LOCALBASE}/lib/mysql \
		--with-mysql-includes=${LOCALBASE}/include/mysql

PORTDOCS=	INSTALL README

# MyODBC needs an ODBC driver manager to be installed, and it supports both
# iODBC and unixODBC.  The following variable may be set at built-time to
# either "iodbc" or "unixodbc", with the former being the default:
DRIVER_MANAGER?=	iodbc

.if ${DRIVER_MANAGER} == "unixodbc"
CONFIGURE_ARGS+=	--with-odbc-ini=${LOCALBASE}/etc/odbc.ini \
			--with-unixODBC=${LOCALBASE}
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
.else	# assume we're using iodbc
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-odbc-ini=${LOCALBASE}/etc/libiodbc/odbc.ini
.endif

pre-fetch:
	@${ECHO}
	@${ECHO} "This software works with MySQL 3.x and 4.0."
	@${ECHO} "Building against MySQL version 4.1 or 5.0 is not yet supported."
	@${ECHO}

# Allow a new value of ODBCVER to be set at build-time
.if defined(ODBCVER)
post-patch:
	cd ${WRKSRC}; \
	${MV} myodbc.h myodbc.h.orig; \
	${SED} -e "s/ODBCVER 0x0250/ODBCVER ${ODBCVER}/" < myodbc.h.orig > myodbc.h
.endif

# XXX untested
.if defined(STATIC)
CONFIGURE_ARGS+=	--enable-shared=no \
			--enable-static=yes
.endif

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
# Install the INSTALL file as well, since it describes how to set up odbc.ini
	@ ${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
