PORTNAME=	cargo-make
DISTVERSION=	0.37.24
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Rust task runner and build tool
WWW=		https://sagiegurari.github.io/cargo-make/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	sagiegurari

PLIST_FILES=	bin/cargo-make \
		bin/makers

.include <bsd.port.mk>
