PORTNAME=	resolv-replace
PORTVERSION=	0.2.0
CATEGORIES=	dns rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Replace Socket DNS with Resolv
WWW=		https://github.com/ruby/resolv-replace

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-resolv>=0:dns/rubygem-resolv

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
