# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	solarwolf
PORTVERSION=	1.5
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	https://www.pygame.org/shredwheat/solarwolf/

MAINTAINER=	mail@maxlor.com
COMMENT=	Action/arcade game originally based of SolarFox on the Atari 2600

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/lgpl.txt

RUN_DEPENDS=	${PYGAME}

USES=		python:2.7 shebangfix
SHEBANG_FILES=	solarwolf.py

DESKTOP_ENTRIES=	"SolarWolf" "${COMMENT}" "solarwolf" \
	"solarwolf" "Game;ArcadeGame;" false

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/solarwolf
	(cd ${WRKSRC}; tar -cf - --exclude ".xvpics" --exclude "dist" .) | \
		(cd ${STAGEDIR}${PREFIX}/share/solarwolf; tar --unlink -xf -)
	${PRINTF} "#!/bin/sh\nexec ${PYTHON_CMD} ${PREFIX}/share/solarwolf/solarwolf.py\n" \
		> ${STAGEDIR}${PREFIX}/bin/solarwolf
	${CP} ${WRKSRC}/dist/solarwolf.6.gz ${STAGEDIR}${MAN6PREFIX}/man/man6/
	${CP} ${WRKSRC}/dist/solarwolf.png ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
