PORTNAME=	rake-compiler
PORTVERSION=	1.1.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Build and package Ruby extensions (C, Java) using Rake

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/rake-compiler

.include <bsd.port.mk>
