PORTNAME=	hyperfine
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19.0
PORTREVISION=	5
CATEGORIES=	benchmarks

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Command-line benchmarking tool
WWW=		https://github.com/sharkdp/hyperfine

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=	cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

PLIST_FILES=	bin/hyperfine

.include <bsd.port.mk>
