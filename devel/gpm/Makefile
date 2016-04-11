# Created by: Luke Jee <lukejee@gmail.com>
# $FreeBSD$

PORTNAME=	gpm
PORTVERSION=	1.4.0
CATEGORIES=	devel

MAINTAINER=	lukejee@gmail.com
COMMENT=	Go Package Manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	pote
GH_TAGNAME=	fef7bf2

NO_BUILD=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/gpm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gpm ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
