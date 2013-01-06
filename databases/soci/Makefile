# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	soci
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	The C++ Database Access Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes
USE_TCL_BUILD=	85
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--include-prefix=${PREFIX}/include/soci \
		--lib-prefix=${PREFIX}/lib
ALL_TARGET=	build_libs
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL PGSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
CONFIGURE_ARGS+=--mysql-include=${LOCALBASE}/include/mysql \
		--mysql-lib=${LOCALBASE}/lib/mysql
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
PLIST_SUB+=	PGSQL=""
CONFIGURE_ARGS+=--postgresql-include=${LOCALBASE}/include \
		--postgresql-lib=${LOCALBASE}/lib
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s/ldconfig/true/" ${WRKSRC}/build/unix/install.tcl

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
