PORTNAME=	lets
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.59
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI task runner for developers
WWW=		https://lets-cli.org/ \
		https://github.com/lets-cli/lets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	tree-sitter-grammars:tree-sitter-yaml:v${TREE_SITTER_YAML_VERSION}:tree_sitter_yaml \
		tree-sitter:tree-sitter:${TREE_SITTER_REV}:tree_sitter

GO_MODULE=	github.com/lets-cli/lets

TREE_SITTER_YAML_VERSION=	0.7.0
TREE_SITTER_REV=	68c1fb66bdaa720856979756d076c555a464aa00

PLIST_FILES=	bin/lets

pre-patch:
	@${RM} -r ${WRKSRC}/vendor/github.com/tree-sitter-grammars/tree-sitter-yaml
	@${LN} -s ${WRKDIR}/tree-sitter-yaml-${TREE_SITTER_YAML_VERSION} \
		${WRKSRC}/vendor/github.com/tree-sitter-grammars/tree-sitter-yaml
	@${RM} -r ${WRKSRC}/vendor/github.com/tree-sitter/go-tree-sitter/include \
		${WRKSRC}/vendor/github.com/tree-sitter/go-tree-sitter/src
	@${LN} -s ${WRKDIR}/tree-sitter-${TREE_SITTER_REV}/lib/include \
		${WRKSRC}/vendor/github.com/tree-sitter/go-tree-sitter/include
	@${LN} -s ${WRKDIR}/tree-sitter-${TREE_SITTER_REV}/lib/src \
		${WRKSRC}/vendor/github.com/tree-sitter/go-tree-sitter/src

.include <bsd.port.mk>
