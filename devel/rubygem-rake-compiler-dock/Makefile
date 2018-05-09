# $FreeBSD$

PORTNAME=	rake-compiler-dock
PORTVERSION=	0.6.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Cross compiler environment for building Windows binary gems

LICENSE=	MIT

NO_ARCH=	yes
USES=		gem shebangfix
USE_RUBY=	yes

SHEBANK_LANG=	bash
SHEBANG_FILES=	build/runas

PLIST_FILES=	bin/rake-compiler-dock

.include <bsd.port.mk>
