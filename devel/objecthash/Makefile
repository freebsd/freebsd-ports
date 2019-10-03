# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	objecthash
PORTVERSION=	20160802
PORTREVISION=	9
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-language way to cryptographically hash JSON objects

LICENSE=	APACHE20

LIB_DEPENDS=	libicudata.so:devel/icu \
		libjson-c.so:devel/json-c

USES=		pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	benlaurie
GH_PROJECT=	objecthash
GH_TAGNAME=	770874c

USE_LDCONFIG=	yes

ALL_TARGET=	libobjecthash.so

PLIST_FILES=	include/objecthash.h lib/libobjecthash.so

do-install:
	${INSTALL_LIB} ${WRKSRC}/libobjecthash.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/objecthash.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
