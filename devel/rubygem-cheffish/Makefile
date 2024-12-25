PORTNAME=	cheffish
PORTVERSION=	17.1.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library to manipulate Chef in Chef
WWW=		https://github.com/chef/cheffish

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-chef-utils>=17.0:sysutils/rubygem-chef-utils \
		rubygem-chef-zero>=14.0:sysutils/rubygem-chef-zero \
		rubygem-logger15>=0<1.6.0:devel/rubygem-logger15 \
		rubygem-net-ssh>=0,2:security/rubygem-net-ssh

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
