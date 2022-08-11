PORTNAME=	pry-remote
PORTVERSION=	0.1.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Connect to Pry remotely using DRb

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-pry>=0.9<1:devel/rubygem-pry \
		rubygem-slop3>=3.0<4:devel/rubygem-slop3

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/pry-remote

.include <bsd.port.mk>
