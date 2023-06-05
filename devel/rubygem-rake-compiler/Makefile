PORTNAME=	rake-compiler
PORTVERSION=	1.2.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Build and package Ruby extensions (C, Java) using Rake
WWW=		https://github.com/rake-compiler/rake-compiler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/rake-compiler

.include <bsd.port.mk>
