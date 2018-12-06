# $FreeBSD$

PORTNAME=	rubocop
PORTVERSION=	0.61.0
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby code style checking tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-jaro_winkler>=1.5.1:devel/rubygem-jaro_winkler \
		rubygem-parallel>=1.10:sysutils/rubygem-parallel \
		rubygem-parser>=2.5:devel/rubygem-parser \
		rubygem-powerpack>=0.1:devel/rubygem-powerpack \
		rubygem-rainbow>=2.2.2:devel/rubygem-rainbow \
		rubygem-ruby-progressbar>=1.7:devel/rubygem-ruby-progressbar \
		rubygem-unicode-display_width>=1.4.0:devel/rubygem-unicode-display_width

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/rubocop

.include <bsd.port.mk>
