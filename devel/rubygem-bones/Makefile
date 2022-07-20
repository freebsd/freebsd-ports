PORTNAME=	bones
PORTVERSION=	3.9.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to create new projects from code skeleton

LICENSE=	MIT

RUN_DEPENDS=	rubygem-little-plugger>=1.1<2:devel/rubygem-little-plugger \
		rubygem-loquacious>=1.9<2:devel/rubygem-loquacious \
		rubygem-rake>=13.0<14:devel/rubygem-rake \
		rubygem-rdoc>=6.0<7:devel/rubygem-rdoc

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/bones

.include <bsd.port.mk>
