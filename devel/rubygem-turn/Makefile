PORTNAME=	turn
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	New output format for Test::Unit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-ansi>=0:devel/rubygem-ansi \
		rubygem-minitest>=4:devel/rubygem-minitest

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/turn

.include <bsd.port.mk>
