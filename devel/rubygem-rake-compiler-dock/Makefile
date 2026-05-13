PORTNAME=	rake-compiler-dock
PORTVERSION=	1.12.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Cross compiler environment for building Windows binary gems
WWW=		https://github.com/rake-compiler/rake-compiler-dock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	build/runas

PLIST_FILES=	bin/rake-compiler-dock

.include <bsd.port.mk>
