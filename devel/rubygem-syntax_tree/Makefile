PORTNAME=	syntax_tree
PORTVERSION=	6.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parser based on ripper
WWW=		https://ruby-syntax-tree.github.io/syntax_tree/ \
		https://github.com/ruby-syntax-tree/syntax_tree

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-prettier_print>=1.2.0:devel/rubygem-prettier_print

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/stree \
		bin/yarv

.include <bsd.port.mk>
