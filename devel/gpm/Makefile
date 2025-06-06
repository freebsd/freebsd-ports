PORTNAME=	gpm
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	26
CATEGORIES=	devel

MAINTAINER=	lukejee@gmail.com
COMMENT=	Go Package Manager
WWW=		https://github.com/pote/gpm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Unmaintained upstream and no longer works as intended
EXPIRATION_DATE=2025-06-30

RUN_DEPENDS=	bash:shells/bash

USES=		go:run

USE_GITHUB=	yes
GH_ACCOUNT=	pote

NO_BUILD=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/gpm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gpm ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
