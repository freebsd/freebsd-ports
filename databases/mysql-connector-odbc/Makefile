# New ports collection makefile for:	MyODBC
# Date created:				22 Mar 2004
# Whom:					sergey@migsoft.com.ua
#
# $FreeBSD$
#

PORTNAME=	mysql-connector-odbc
PORTVERSION=	3.51.12
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MyODBC3
PKGNAMESUFFIX=	-${DRIVER_MANAGER}-mysql${MYSQL_VER}

MAINTAINER=	sergey@network-asp.biz
COMMENT=	ODBC driver for MySQL${MYSQL_VER} / ${DRIVER_MANAGER}

USE_MYSQL=		yes
BROKEN_WITH_MYSQL=	323

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15 libltdl:15
INSTALLS_SHLIB=	yes
CFLAGS=		-L${LOCALBASE}/lib
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-mysql-path=${LOCALBASE} --without-samples \
		--disable-gui --enable-test=no

PLIST_SUB=	VER=${PORTVERSION}

PORTDOCS=	README

# MyODBC needs an ODBC driver manager to be installed, and it supports both
# iODBC and unixODBC.  The following variable may be set at built-time to
# either "iodbc" or "unixodbc", with the former being the default:
DRIVER_MANAGER?=	unixodbc

.if ${DRIVER_MANAGER} == "unixodbc"
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc-ini=${LOCALBASE}/etc/odbc.ini \
			--with-unixODBC=${LOCALBASE}
CFLAGS+=		${PTHREAD_LIBS}
.else	# assume we're using iodbc
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iODBC=${LOCALBASE} \
			--with-iodbc-includes=${LOCALBASE}/include \
			--with-iodbc-libs=${LOCALBASE}/lib \
			--with-odbc-ini=${LOCALBASE}/etc/libiodbc/odbc.ini
EXTRA_PATCHES=		${PATCHDIR}/myodbc-iodbc-patch
.endif

post-patch:
# Allow a new value of ODBCVER to be set at build-time
.if defined(ODBCVER)
	@${REINPLACE_CMD} -e "s|ODBCVER 0x0250|ODBCVER ${ODBCVER}|" ${WRKSRC}/myodbc.h
.endif

# XXX untested
.if defined(STATIC)
CONFIGURE_ARGS+=	--enable-shared=no --enable-static=yes
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.if !exists(${PREFIX}/lib/libmyodbc3.so.0)
	@${LN} -s ${PREFIX}/lib/libmyodbc3-${PORTVERSION}.so ${PREFIX}/lib/libmyodbc3.so.0
.endif
.if !exists(${PREFIX}/lib/libmyodbc3_r.so.0)
	@${LN} -s ${PREFIX}/lib/libmyodbc3_r-${PORTVERSION}.so ${PREFIX}/lib/libmyodbc3_r.so.0
.endif

.include <bsd.port.mk>
