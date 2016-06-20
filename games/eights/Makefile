# Created by: Bob Bomar <bob@fly.homeunix.org>
# $FreeBSD$

PORTNAME=	eights
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://dxkelly.freeshell.org/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text based card game, the objective is to get rid of all your cards

USES=	dos2unix
DOS2UNIX_FILES=	eights.c
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/eights

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
