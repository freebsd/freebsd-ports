PORTNAME=	pt2-clone
PORTVERSION=	1.78
DISTVERSIONPREFIX=	v
CATEGORIES=	audio
MASTER_SITES=	LOCAL/ehaupt:extras
DISTFILES=	${PORTNAME}-extras-${EXTRASVERSION}${EXTRACT_SUFX}:extras

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Amiga ProTracker clone
WWW=		https://16-bits.org/pt2.php

LICENSE=	WTFPL

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cmake desktop-file-utils localbase:ldflags sdl
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	8bitbubsy
USE_SDL=	sdl2

CFLAGS_i386+=	-msse2

PLIST_FILES=	bin/pt2-clone \
		share/applications/pt2-clone.desktop \
		share/man/man1/pt2-clone.1.gz \
		share/pixmaps/pt2-clone.png

EXTRASVERSION=	2

post-patch:
	@${REINPLACE_CMD} -e "s|^Icon=.*|Icon=${PORTNAME}|" \
		${WRKSRC}/release/other/Freedesktop.org*/*.desktop

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/share/man/man1 \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/release/other/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}-extras-${EXTRASVERSION}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/release/other/Freedesktop.org*/*.desktop \
		${STAGEDIR}${DESKTOPDIR}/${PORTNAME}.desktop
	${INSTALL_DATA} ${WRKSRC}/release/other/Freedesktop.org*/*.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
