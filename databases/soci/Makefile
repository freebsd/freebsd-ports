# New ports collection makefile for:	soci
# Date created:		2010-09-13
# Whom:			Julien Laffaye <kimelto@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	soci
PORTVERSION=	3.0.0
CATEGORIES=	databases
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	kimelto@gmail.com
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

OPTIONS=	MYSQL "Build MySQL driver" on \
		PGSQL "Build PostgreSQL driver" on

.include <bsd.port.pre.mk>

.ifdef (WITH_MYSQL)
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
CONFIGURE_ARGS+=--mysql-include=${LOCALBASE}/include/mysql \
		--mysql-lib=${LOCALBASE}/lib/mysql
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.ifdef (WITH_PGSQL)
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

.include <bsd.port.post.mk>
