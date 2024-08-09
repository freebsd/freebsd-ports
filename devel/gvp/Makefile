PORTNAME=	gvp
PORTVERSION=	0.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	22
CATEGORIES=	devel

MAINTAINER=	lukejee@gmail.com
COMMENT=	Go Versioning Manager
WWW=		https://github.com/pote/gvp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

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
