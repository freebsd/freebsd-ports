PORTNAME=	sonivox
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.12
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fork of the AOSP 'platform_external_sonivox' to use out of Android
WWW=		https://github.com/pedrolcl/sonivox

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pedrolcl

CXXFLAGS+=	-DO_LARGEFILE=0 # workaround for linuxism in tests

CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
