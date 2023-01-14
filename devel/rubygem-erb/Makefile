PORTNAME=	erb
PORTVERSION=	3.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy to use but powerful templating system for Ruby
WWW=		https://github.com/ruby/erb

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-cgi>=0.3.3:www/rubygem-cgi

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/erb

.include <bsd.port.mk>
