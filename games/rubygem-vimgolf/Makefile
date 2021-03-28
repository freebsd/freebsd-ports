# $FreeBSD$

PORTNAME=	vimgolf
PORTVERSION=	0.4.9
CATEGORIES=	games rubygems
MASTER_SITES=	RG

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	CLI client for vimgolf.com

LICENSE=	MIT

RUN_DEPENDS=	rubygem-highline>=0:devel/rubygem-highline \
		rubygem-json_pure>=0:devel/rubygem-json_pure \
		rubygem-thor>=0.14.6:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
