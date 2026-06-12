PORTNAME=	erb
PORTVERSION=	4.0.3.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Easy to use but powerful templating system for Ruby
WWW=		https://github.com/ruby/erb

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
#LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-cgi>=0.3.3:www/rubygem-cgi

USES=		gem

PLIST_FILES=	bin/erb

.include <bsd.port.mk>
