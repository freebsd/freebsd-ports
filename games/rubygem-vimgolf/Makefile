# $FreeBSD$

PORTNAME=	vimgolf
PORTVERSION=	0.4.8
CATEGORIES=	games rubygems
MASTER_SITES=	RG

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	CLI client for vimgolf.com

LICENSE=	MIT

RUN_DEPENDS=	rubygem-thor>=0.14.6:devel/rubygem-thor \
		rubygem-json_pure>=0:devel/rubygem-json_pure \
		rubygem-highline>=0:devel/rubygem-highline

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem
PLIST_FILES=	bin/vimgolf

.include <bsd.port.mk>
