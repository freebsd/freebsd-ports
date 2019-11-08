# Created by: <benlutz@datacomm.ch>
# $FreeBSD$

PORTNAME=	freedroid
PORTVERSION=	1.0.2
PORTREVISION=	19
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}Classic/FreedroidClassic-${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Clone of the Commodore game Paradroid

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		iconv jpeg sdl
USE_SDL=	mixer image sdl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=

DESKTOP_ENTRIES=	"Freedroid Classic" "${COMMENT}" \
			"${DATADIR}/graphics/999.png" \
			"freedroid" "Game;ArcadeGame;" false

post-extract:
.for d in graphics map sound
	@${FIND} ${WRKSRC}/${d} -type f -name "Makefile*" -print0 | \
		${XARGS} -0 ${RM}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's#-lSDL # #;' \
				${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's#$$(man_MANS) mac-osx ##;' \
				${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's#\#include \"mac-osx/getopt\.h\"##;' \
				${WRKSRC}/src/system.h

.include <bsd.port.mk>
