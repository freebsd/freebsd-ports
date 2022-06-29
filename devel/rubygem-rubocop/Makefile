PORTNAME=	rubocop
PORTVERSION=	1.31.0
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby code style checking tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-parallel>=1.10<2:sysutils/rubygem-parallel \
		rubygem-parser>=3.1.0.0:devel/rubygem-parser \
		rubygem-rainbow>=2.2.2<4.0:devel/rubygem-rainbow \
		rubygem-regexp_parser>=1.8<3.0:textproc/rubygem-regexp_parser \
		rubygem-rexml>=3.2.5<4.0:textproc/rubygem-rexml \
		rubygem-rubocop-ast>=1.18.0<2.0:devel/rubygem-rubocop-ast \
		rubygem-ruby-progressbar>=1.7<2:devel/rubygem-ruby-progressbar \
		rubygem-unicode-display_width>=1.4.0<3.0:devel/rubygem-unicode-display_width

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/rubocop

CPE_VENDOR=	rubocop_project

.include <bsd.port.mk>
