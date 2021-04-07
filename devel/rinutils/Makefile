PORTNAME=	rinutils
DISTVERSION=	0.8.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/shlomif/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	C11 / gnu11 utilities C library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake perl5 pkgconfig tar:xz
USE_PERL5=	build
CMAKE_OFF=	WITH_TEST_SUITE

.include <bsd.port.mk>
