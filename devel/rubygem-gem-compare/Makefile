PORTNAME=	gem-compare
PORTVERSION=	1.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RubyGems plugin for comparing gem versions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_RUBY27=	yes

RUN_DEPENDS=	rubygem-diffy>=0:textproc/rubygem-diffy \
		rubygem-gemnasium-parser>=0:devel/rubygem-gemnasium-parser \
		rubygem-json>=0:devel/rubygem-json \
		rubygem-rainbow>=0:devel/rubygem-rainbow

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	test/gemfiles/*/*/lorem

.include <bsd.port.mk>
