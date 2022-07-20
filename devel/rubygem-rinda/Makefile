PORTNAME=	rinda
PORTVERSION=	0.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Linda distributed computing paradigm in Ruby

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-drb>=0:devel/rubygem-drb \
		rubygem-forwardable>=0:devel/rubygem-forwardable \
		rubygem-ipaddr>=0:net/rubygem-ipaddr

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
