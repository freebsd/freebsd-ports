PORTNAME=	rinda
PORTVERSION=	0.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Linda distributed computing paradigm in Ruby
WWW=		https://github.com/ruby/rinda

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-drb>=0:devel/rubygem-drb \
		rubygem-forwardable>=0:devel/rubygem-forwardable \
		rubygem-ipaddr>=0:net/rubygem-ipaddr

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
