# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	0.03
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical x86 CPU opcode calculator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pkgconfig qt:5
GNU_CONFIGURE=	yes
USE_QT=		buildtools_build qmake_build core gui widgets

USE_GITHUB=	yes
GH_ACCOUNT=	horsicq
GH_PROJECT=	XOpcodeCalc XOptions:xo
GH_TAGNAME=	01bba2a:xo
GH_SUBDIR=	XOptions:xo

post-extract:
	@${CHMOD} +x ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/release/xocalc \
		${STAGEDIR}${PREFIX}/bin
	cd ${INSTALL_WRKSRC}/DEBIAN && ${COPYTREE_SHARE} hicolor \
		${STAGEDIR}${PREFIX}/share/icons

.include <bsd.port.mk>

PATCH_ARGS+=	-l
