# $FreeBSD$

PORTNAME=	rake-compiler
PORTVERSION=	0.9.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Build and package Ruby extensions (C, Java) using Rake

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rake-compiler

.include <bsd.port.mk>
