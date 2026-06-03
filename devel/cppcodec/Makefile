PORTNAME=	cppcodec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2-11
DISTVERSIONSUFFIX=	-g8019b8b
CATEGORIES=	devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Library to encode/decode base64, base64url, base32, base32hex and hex
WWW=		https://github.com/tplgy/cppcodec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	tplgy

CMAKE_OFF+=	CPPCODEC_BUILD_TESTING

.include <bsd.port.mk>
