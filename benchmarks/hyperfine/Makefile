PORTNAME=	hyperfine
DISTVERSIONPREFIX=	v
DISTVERSION=	1.21.0
CATEGORIES=	benchmarks

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command-line benchmarking tool
WWW=		https://github.com/sharkdp/hyperfine

LICENSE=	Apache-2.0 MIT MPL-2.0
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_MPL-2.0=	${CARGO_VENDOR_DIR}/colored-3.1.1/LICENSE

USES=	cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

PLIST_FILES=	bin/hyperfine

.include <bsd.port.mk>
