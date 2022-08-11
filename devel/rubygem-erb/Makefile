PORTNAME=	erb
PORTVERSION=	2.2.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy to use but powerful templating system for Ruby

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-cgi>=0:www/rubygem-cgi

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

#PLIST_FILES=	bin/erb

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/erb

.include <bsd.port.mk>
