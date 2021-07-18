# Created by: David Siebörger <drs@rucus.ru.ac.za>

PORTNAME=	xrick
PORTVERSION=	021212
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://www.bigorno.net/xrick/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of Rick Dangerous

# Converted from RESTRICTED
LICENSE=	xrick
LICENSE_NAME=	xrick
LICENSE_TEXT=	Copyright status of the graphics and sounds is uncertain
LICENSE_PERMS=	auto-accept

USES=		gmake jpeg sdl tar:tgz
USE_SDL=	sdl

PLIST_FILES=	bin/xrick man/man6/xrick.6.gz share/xrick/data.zip
PLIST_DIRS=	share/xrick

post-patch:
	@${REINPLACE_CMD} -e 's|sysarg_args_data = NULL|sysarg_args_data = "${PREFIX}/share/xrick/data.zip"|' ${WRKSRC}/src/sysarg.c
	@${REINPLACE_CMD} 's|gcc|${CC}|; s|-g||; s|-O2|${CFLAGS}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/IMG_SPLASH/s,^,extern ,' \
		${WRKSRC}/include/img.h
	@${REINPLACE_CMD} -E '/WAV_(BOMBSHHT|BONUS|BOX|BULLET|JUMP|WALK);/ \
		s,^,//,' ${WRKSRC}/src/game.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrick ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xrick.6.gz ${STAGEDIR}${PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xrick
	${INSTALL_DATA} ${WRKSRC}/data.zip ${STAGEDIR}${PREFIX}/share/xrick

.include <bsd.port.mk>
