PORTNAME=	gvp
PORTVERSION=	0.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	26
CATEGORIES=	devel

MAINTAINER=	lukejee@gmail.com
COMMENT=	Go Versioning Manager
WWW=		https://github.com/pote/gvp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

DEPRECATED=	Unmaintained upstream and no longer works as intended
EXPIRATION_DATE=2025-06-30

RUN_DEPENDS=	bash:shells/bash

USES=		go:run shebangfix

SHEBANG_FILES=	bin/gvp

USE_GITHUB=	yes
GH_ACCOUNT=	pote

NO_BUILD=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/gvp

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gvp ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
