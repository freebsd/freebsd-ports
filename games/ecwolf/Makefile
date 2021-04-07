PORTNAME=	ecwolf
PORTVERSION=	1.3.3
PORTREVISION=	1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	http://maniacsvault.net/ecwolf/files/ecwolf/1.x/

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Source port for Wolfenstein 3D, Spear of Destiny

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/license-gpl.txt

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lang gnome jpeg localbase:ldflags \
		pkgconfig sdl tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_SDL=	mixer sdl

SUB_FILES=	ecwolf pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/${PORTNAME}/${PORTNAME} \
		share/${PORTNAME}/${PORTNAME}.pk3

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${BUILD_WRKSRC}/${PORTNAME}.pk3 \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
