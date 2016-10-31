# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	imv
PORTVERSION=	2.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	t@tobik.me
COMMENT=	Simple image viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreeimage.so:graphics/freeimage

USES=		desktop-file-utils gmake
USE_SDL=	sdl2 ttf2

USE_GITHUB=	yes
GH_ACCOUNT=	eXeC64

ALL_TARGET=	imv

MAKE_ARGS=	V=1

PLIST_FILES=	bin/imv \
		man/man1/imv.1.gz \
		share/applications/imv.desktop

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/imv \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/files/imv.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/doc/imv.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
