# New ports collection makefile for:	MyODBC
# Date created:				22 Mar 2004
# Whom:					sergey@migsoft.com.ua
#
# $FreeBSD$
#

PORTNAME=	mysql-connector-odbc
PORTVERSION=	3.51.26
DISTVERSIONSUFFIX=	r1127
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	Connector-ODBC/3.51
PKGNAMESUFFIX=	-${DRIVER_MANAGER}-mysql${MYSQL_VER}

MAINTAINER=	sergey@network-asp.biz
COMMENT=	ODBC driver for MySQL${MYSQL_VER} / ${DRIVER_MANAGER}

USE_MYSQL=		yes
DEFAULT_MYSQL_VER=	51
IGNORE_WITH_MYSQL=	55

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool libltdl
USE_LDCONFIG=	yes
CFLAGS+=		-L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-mysql-path=${LOCALBASE} --without-samples \
		--disable-gui --enable-test=no

PLIST_SUB=	VER=${PORTVERSION}

PORTDOCS=	ChangeLog INSTALL LICENSE.exceptions LICENSE.gpl \
		README README.debug

# MyODBC needs an ODBC driver manager to be installed, and it supports both
# iODBC and unixODBC.

.if defined(WITH_IODBC) && defined(WITH_UNIXODBC)
IGNORE=		selected mutually exclusive options: WITH_IODBC and WITH_UNIXODBC
.endif

.if !defined(WITH_IODBC) && !defined(WITH_UNIXODBC)
WITH_UNIXODBC?=	yes
.endif

.if defined(WITH_UNIXODBC)
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
BUILD_DEPENDS=		unixODBC>=2.2.14_1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc-ini=${LOCALBASE}/etc/odbc.ini \
			--with-unixODBC=${LOCALBASE}
CFLAGS+=		${PTHREAD_LIBS}
DRIVER_MANAGER=		unixodbc
.elif defined(WITH_IODBC)
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iODBC=${LOCALBASE} \
			--with-iodbc-includes=${LOCALBASE}/include \
			--with-iodbc-libs=${LOCALBASE}/lib \
			--with-odbc-ini=${LOCALBASE}/etc/libiodbc/odbc.ini
EXTRA_PATCHES=		${PATCHDIR}/myodbc-iodbc-patch
DRIVER_MANAGER=		iodbc
.endif

post-patch:
# Allow a new value of ODBCVER to be set at build-time
.if defined(ODBCVER)
	@${REINPLACE_CMD} -e "s|ODBCVER 0x0250|ODBCVER ${ODBCVER}|" ${WRKSRC}/myodbc.h
.endif
	@${REINPLACE_CMD} -e "s|^\(readmedir =\).*|\1 ${DOCSDIR}|" ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e " \
	/^	/s|install-readmeDATA||; \
	/^install-data-am:/s|install-readmeDATA||; \
	" ${WRKSRC}/Makefile.in
.endif

# XXX untested
.if defined(STATIC)
CONFIGURE_ARGS+=	--enable-shared=no --enable-static=yes
.endif

post-install:
.if !exists(${PREFIX}/lib/libmyodbc3.so.0)
	@${LN} -s ${PREFIX}/lib/libmyodbc3-${PORTVERSION}.so ${PREFIX}/lib/libmyodbc3.so.0
.endif
.if !exists(${PREFIX}/lib/libmyodbc3_r.so.0)
	@${LN} -s ${PREFIX}/lib/libmyodbc3_r-${PORTVERSION}.so ${PREFIX}/lib/libmyodbc3_r.so.0
.endif

.include <bsd.port.mk>
