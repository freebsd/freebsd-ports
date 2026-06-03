PORTNAME=	pacman.c
DISTVERSION=	g20251120
CATEGORIES=	games
MASTER_SITES=	LOCAL/ehaupt:icon
DISTFILES=	${PORTNAME}-icon-${ICON_VERSION}${EXTRACT_SUFX}:icon

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Simple Pacman clone written in C99
WWW=		https://floooh.github.io/pacman.c/pacman.html \
		https://github.com/floooh/pacman.c

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libasound.so:audio/alsa-lib

USES=		cmake gl localbase:ldflags xorg
USE_GITHUB=	yes
GH_ACCOUNT=	floooh
GH_TAGNAME=	be5f12c
USE_GL+=	gl
USE_XORG=	x11 xcursor xi

DESKTOP_ENTRIES=	"pacman.c" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
			"${PORTNAME}" \
			"" \
			false

PLIST_FILES=	bin/pacman.c \
		share/man/man6/pacman.c.6.gz \
		share/pixmaps/pacman.c.png

ICON_VERSION=	1

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/pacman \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 \
		${STAGEDIR}${PREFIX}/share/man/man6
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-icon-${ICON_VERSION}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
