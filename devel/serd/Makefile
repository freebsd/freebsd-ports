# Created by: meka
# $FreeBSD$

PORTNAME=	serd
PORTVERSION=	0.24.0
CATEGORIES=	devel
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	meka@tilda.center
COMMENT=	C library for RDF syntax

LICENSE=	ISC
LICENSE_NAME=	ISC
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		pkgconfig tar:bzip2 waf
USE_LDCONFIG=	yes
PKG_CONFIG_PATH=	${PREFIX}/libdata/pkgconfig
CONFIGURE_ARGS+=	PKG_CONFIG_PATH=${PKG_CONFIG_PATH}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig ${STAGEDIR}${PREFIX}/libdata/
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1 ${STAGEDIR}${PREFIX}/man/
	${RMDIR} ${STAGEDIR}${PREFIX}/share/man

.include <bsd.port.mk>
