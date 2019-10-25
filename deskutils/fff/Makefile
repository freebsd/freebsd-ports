# $FreeBSD$

PORTNAME=	fff
DISTVERSION=	2.1
CATEGORIES=	deskutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Simple file manager written in Bash

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix
SHEBANG_FILES=	fff
USE_GITHUB=	yes
GH_ACCOUNT=	dylanaraps

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/fff share/man/man1/fff.1

.include <bsd.port.mk>
