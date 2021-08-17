PORTNAME=	vimgolf
PORTVERSION=	0.5.0
CATEGORIES=	games rubygems
MASTER_SITES=	RG

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	CLI client for vimgolf.com

LICENSE=	MIT

RUN_DEPENDS=	rubygem-highline>=2.0:devel/rubygem-highline \
		rubygem-json_pure>=2.3:devel/rubygem-json_pure \
		rubygem-thor>=1.0:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
