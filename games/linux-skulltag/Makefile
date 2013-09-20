# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	skulltag
PORTVERSION=	0.9.8a
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://skulltag.net/download/files/release/
DISTFILES=	st-v098a_linux-base.tar.bz2 st-v098a_linux-x86.tar.bz2

MAINTAINER=	edwin@mavetju.org
COMMENT=	Doom/Doom2/Heretic engine

RUN_DEPENDS=	${LINUXBASE}/lib/libfmodexp-4.24.16.so:${PORTSDIR}/audio/linux-fmodapi

USE_LINUX=	yes
USE_LINUX_APPS=	sdl12
ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
NO_BUILD=	yes

SUB_FILES=	skulltag.sh pkg-message

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/skulltag ${PREFIX}/bin/skulltag.bin
	${INSTALL_PROGRAM} ${WRKDIR}/skulltag-server ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/skulltag.sh ${PREFIX}/bin/skulltag
	${MKDIR} ${PREFIX}/share/games/skulltag
	${MKDIR} ${PREFIX}/share/games/skulltag/skins
	${MKDIR} ${PREFIX}/share/games/skulltag/announcer
	for f in ${WRKDIR}/announcer/*; do ${INSTALL_DATA} $${f} ${PREFIX}/share/games/skulltag/announcer; done
	for f in ${WRKDIR}/skins/*; do ${INSTALL_DATA} $${f} ${PREFIX}/share/games/skulltag/skins; done
	for f in liboutput_sdl.so libsnes_spc.so skulltag.pk3 skulltag_data.pk3; do ${INSTALL_DATA} ${WRKDIR}/$${f} ${PREFIX}/share/games/skulltag; done

post-install:
	${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=	Needs the newer FreeBSD 8.0 Linuxolator
.endif

.include <bsd.port.post.mk>
