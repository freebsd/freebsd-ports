PORTNAME=	ggwave
DISTVERSIONPREFIX=	ggwave-v
DISTVERSION=	0.4.1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tiny data-over-sound library
WWW=		https://github.com/ggerganov/ggwave

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ggerganov

CMAKE_OFF=	GGWAVE_BUILD_TESTS GGWAVE_BUILD_EXAMPLES GGWAVE_SUPPORT_SWIFT
CMAKE_TESTING_ON=	GGWAVE_BUILD_TESTS

PLIST_FILES=	include/ggwave/ggwave.h \
		lib/libggwave.so

post-install:
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} ggwave ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
