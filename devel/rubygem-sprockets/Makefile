PORTNAME=	sprockets
PORTVERSION=	4.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rack-based asset packaging system

LICENSE=	MIT

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-rack>=1,3<3,3:www/rubygem-rack

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/sprockets

CPE_VENDOR=	sprockets_project

.include <bsd.port.mk>
