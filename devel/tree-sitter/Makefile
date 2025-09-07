PORTNAME=	tree-sitter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.25.9
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Incremental parser generator
WWW=		https://tree-sitter.github.io/tree-sitter/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtree-sitter.so.*

.include <bsd.port.mk>
