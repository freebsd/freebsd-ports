PORTNAME=	tree-sitter-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.25.8
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	amad@atl.tools
COMMENT=	CLI tool for developing, testing, and using Tree-sitter parsers
WWW=		https://tree-sitter.github.io/tree-sitter/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/node:www/node24

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	tree-sitter
GH_PROJECT=	tree-sitter

CARGO_BUILD_ARGS=	-p tree-sitter-cli
CARGO_INSTALL_PATH=	cli
# tests require cloning fixtures.
CARGO_TEST=		no

PLIST_FILES=	bin/tree-sitter

.include <bsd.port.mk>
