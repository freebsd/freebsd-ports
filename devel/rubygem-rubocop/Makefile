PORTNAME=	rubocop
PORTVERSION=	1.65.1
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby code style checking tool
WWW=		https://rubocop.org/ \
		https://github.com/rubocop/rubocop

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-json>=2.3<3:devel/rubygem-json \
		rubygem-language_server-protocol>=3.17.0:devel/rubygem-language_server-protocol \
		rubygem-parallel>=1.10<2:sysutils/rubygem-parallel \
		rubygem-parser>=3.3.0.2:devel/rubygem-parser \
		rubygem-rainbow>=2.2.2<4.0:devel/rubygem-rainbow \
		rubygem-regexp_parser>=2.4<3.0:textproc/rubygem-regexp_parser \
		rubygem-rexml>=3.2.5<4.0:textproc/rubygem-rexml \
		rubygem-rubocop-ast>=1.31.1<2.0:devel/rubygem-rubocop-ast \
		rubygem-ruby-progressbar>=1.7<2:devel/rubygem-ruby-progressbar \
		rubygem-unicode-display_width>=2.4.0<3.0:devel/rubygem-unicode-display_width

USES=		cpe gem

NO_ARCH=	yes

PLIST_FILES=	bin/rubocop

CPE_VENDOR=	rubocop_project

.include <bsd.port.mk>
