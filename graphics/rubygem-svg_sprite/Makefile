PORTNAME=	svg_sprite
PORTVERSION=	1.0.3
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Create SVG sprites using SVG links
WWW=		https://github.com/fnando/svg_sprite

LICENSE=	MIT

RUN_DEPENDS=	rubygem-nokogiri>=0:textproc/rubygem-nokogiri \
		rubygem-svg_optimizer>=0:graphics/rubygem-svg_optimizer \
		rubygem-thor>=0:devel/rubygem-thor

USES=		gem

PLIST_FILES=	bin/svg_sprite

NO_ARCH=	yes

.include <bsd.port.mk>
