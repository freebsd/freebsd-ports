# Created by: Luke Jee <lukejee@gmail.com>
# $FreeBSD$

PORTNAME=	gvp
PORTVERSION=	0.3.0
CATEGORIES=	devel

MAINTAINER=	lukejee@gmail.com
COMMENT=	Go Versioning Manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	bash:shells/bash \
		go:lang/go

USES=		shebangfix

SHEBANG_FILES=	bin/gvp

USE_GITHUB=	yes
GH_ACCOUNT=	pote
GH_TAGNAME=	8bcab74

NO_BUILD=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/gvp

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gvp ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
