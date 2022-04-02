PORTNAME=	gem-compare
PORTVERSION=	1.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RubyGems plugin for comparing gem versions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_RUBY27=	yes

RUN_DEPENDS=	rubygem-curb>=0:ftp/rubygem-curb \
		rubygem-diffy>=0:textproc/rubygem-diffy \
		rubygem-gemnasium-parser>=0:devel/rubygem-gemnasium-parser \
		rubygem-json>=0:devel/rubygem-json \
		rubygem-rainbow>=0:devel/rubygem-rainbow

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
