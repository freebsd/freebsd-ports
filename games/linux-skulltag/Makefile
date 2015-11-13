# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	skulltag
PORTVERSION=	0.9.8a
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://skulltag.net/download/files/release/
DISTFILES=	st-v098a_linux-base.tar.bz2 st-v098a_linux-x86.tar.bz2

MAINTAINER=	edwin@mavetju.org
COMMENT=	Doom/Doom2/Heretic engine

DEPRECATED=	Depends on expiring audio/linux-fmodapi
EXPIRATION_DATE=	2015-11-26

RUN_DEPENDS=	${LINUXBASE}/lib/libfmodexp-4.24.16.so:${PORTSDIR}/audio/linux-fmodapi

USE_LINUX=	yes
USE_LINUX_APPS=	sdl12
ONLY_FOR_ARCHS=	i386 amd64
USES=	tar:bzip2
NO_BUILD=	yes

SUB_FILES=	skulltag.sh pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/skulltag ${STAGEDIR}${PREFIX}/bin/skulltag.bin
	${INSTALL_PROGRAM} ${WRKDIR}/skulltag-server ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/skulltag.sh ${STAGEDIR}${PREFIX}/bin/skulltag
	${MKDIR} ${STAGEDIR}${PREFIX}/share/games/skulltag
	${MKDIR} ${STAGEDIR}${PREFIX}/share/games/skulltag/skins
	${MKDIR} ${STAGEDIR}${PREFIX}/share/games/skulltag/announcer
	for f in ${WRKDIR}/announcer/*; do ${INSTALL_DATA} $${f} ${STAGEDIR}${PREFIX}/share/games/skulltag/announcer; done
	for f in ${WRKDIR}/skins/*; do ${INSTALL_DATA} $${f} ${STAGEDIR}${PREFIX}/share/games/skulltag/skins; done
	for f in liboutput_sdl.so libsnes_spc.so skulltag.pk3 skulltag_data.pk3; do ${INSTALL_DATA} ${WRKDIR}/$${f} ${STAGEDIR}${PREFIX}/share/games/skulltag; done

post-install:
	${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
