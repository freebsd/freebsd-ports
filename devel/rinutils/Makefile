PORTNAME=	rinutils
DISTVERSION=	0.10.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/shlomif/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C11 / gnu11 utilities C library
WWW=		https://github.com/shlomif/rinutils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake perl5 pkgconfig tar:xz
USE_PERL5=	build
CMAKE_OFF=	WITH_TEST_SUITE

NO_ARCH=	yes

.include <bsd.port.mk>
