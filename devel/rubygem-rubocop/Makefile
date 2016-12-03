# $FreeBSD$

PORTNAME=	rubocop
PORTVERSION=	0.46.0
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby code style checking tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-parser>=2.3.1.1:devel/rubygem-parser \
		rubygem-powerpack>=0.1:devel/rubygem-powerpack \
		rubygem-rainbow>=1.99.1:devel/rubygem-rainbow \
		rubygem-ruby-progressbar>=1.7:devel/rubygem-ruby-progressbar \
		rubygem-unicode-display_width>=1.0.1:devel/rubygem-unicode-display_width

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/rubocop

.include <bsd.port.mk>
