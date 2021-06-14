# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	ruby_language_server
PORTVERSION=	0.3.16
CATEGORIES=	lang rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Language server implementation for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord61>=6.1<7:databases/rubygem-activerecord61 \
		rubygem-amatch>=0:textproc/rubygem-amatch \
		rubygem-bundler>=0,1:sysutils/rubygem-bundler \
		rubygem-etc>=0:devel/rubygem-etc \
		rubygem-fuzzy_match>=0:devel/rubygem-fuzzy_match \
		rubygem-json>=0:devel/rubygem-json \
		rubygem-rubocop-performance>=0:devel/rubygem-rubocop-performance \
		rubygem-rubocop-rspec>=0:devel/rubygem-rubocop-rspec \
		rubygem-rubocop>=0:devel/rubygem-rubocop \
		rubygem-sqlite3>=0:databases/rubygem-sqlite3

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/ruby_language_server

.include <bsd.port.mk>
