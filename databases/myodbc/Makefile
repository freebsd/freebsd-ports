# New ports collection makefile for:	MyODBC
# Date created:				22 Mar 2004
# Whom:					sergey@migsoft.com.ua
#
# $FreeBSD$
#

PORTNAME=	myodbc
PORTVERSION=	3.51.11
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=MyODBC3
DISTNAME=	MyODBC-${PORTVERSION}

MAINTAINER=	sergey@network-asp.biz
COMMENT=	ODBC driver for MySQL

USE_MYSQL=		yes
USE_GMAKE=		yes
USE_LIBTOOL_VER=	13
INSTALLS_SHLIB=		yes
CONFIGURE_ARGS+=	--with-mysql-path=${LOCALBASE} --without-samples \
			--disable-gui --enable-test=no

PORTDOCS=	README

# MyODBC needs an ODBC driver manager to be installed, and it supports both
# iODBC and unixODBC.  The following variable may be set at built-time to
# either "iodbc" or "unixodbc", with the former being the default:
DRIVER_MANAGER?=	iodbc

CONFIGURE_ARGS+=
.if ${DRIVER_MANAGER} == "unixodbc"
CONFIGURE_ARGS+=	--with-odbc-ini=${LOCALBASE}/etc/odbc.ini \
			--with-unixODBC=${LOCALBASE}
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
.else	# assume we're using iodbc
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
EXTRA_PATCHES=		${PATCHDIR}/myodbc-iodbc-patch
CONFIGURE_ARGS+=	--with-iODBC=${LOCALBASE} \
			--with-iodbc-includes=${LOCALBASE}/include \
			--with-iodbc-libs=${LOCALBASE}/lib \
			--with-odbc-ini=${LOCALBASE}/etc/libiodbc/odbc.ini
.endif

PKGNAMESUFFIX=	-${DRIVER_MANAGER}-mysql${MYSQL_VER}
COMMENT+=	${MYSQL_VER} / ${DRIVER_MANAGER}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${OSVERSION} >= 503000
BROKEN=		"Does not compile on FreeBSD >=5.x on !i386"
.endif

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
	@ ${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	[ -f ${PREFIX}/lib/libmyodbc3.so.0 ] || ${LN} -s ${PREFIX}/lib/libmyodbc3.so ${PREFIX}/lib/libmyodbc3.so.0
	[ -f ${PREFIX}/lib/libmyodbc3_r.so.0 ] || ${LN} -s ${PREFIX}/lib/libmyodbc3_r.so ${PREFIX}/lib/libmyodbc3_r.so.0

.include <bsd.port.post.mk>
