# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	opencc
PORTVERSION=	11.3
CATEGORIES=	chinese converters
PKGNAMEPREFIX=	bsdconv-

MAINTAINER=	buganini@gmail.com
COMMENT=	OpenCC conversion module for bsdconv

LICENSE=	ISCL

BUILD_DEPENDS=	${LOCALBASE}/bin/bsdconv-mktable:converters/bsdconv
LIB_DEPENDS=	libbsdconv.so:converters/bsdconv \
		libopencc.so:chinese/opencc

PLIST_FILES=	share/bsdconv/inter/OPENCC \
		share/bsdconv/inter/OPENCC.man \
		share/bsdconv/inter/OPENCC.so

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bsdconv/inter/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/bsdconv/inter/OPENCC.so

.include <bsd.port.mk>
