# Created by: Holger Lamm <holger@eit.uni-kl.de>
# $FreeBSD$

PORTNAME=	HeroesOfMightAndMagic
PORTVERSION=	3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=
DISTFILES=

MAINTAINER=	mva@FreeBSD.org
COMMENT=	BSD Installation of the Linux game "Heroes of Might and Magic III"

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_CDROM=	Software is commercial
NO_PACKAGE=	Software is commercial
NO_STAGE=	yes # NO_PACKAGE does not go well with STAGEDIR and pkg_tools

GAMESUBDIR=	games/Heroes3
GAMEDIR=	${STAGEDIR}${PREFIX}/${GAMESUBDIR}

GAMEFILES=	README Heroes_III_Tutorial.pdf icon.bmp icon.xpm
DATAFILES=	*.lod *.snd

.if !defined(CDROM_MOUNT)
BROKEN=	${PKGNAME} requires CDROM_MOUNT to be set to the mount point of the CD
.endif

do-install:
	${MKDIR} ${GAMEDIR}/bin
	${INSTALL_PROGRAM} ${CDROM_MOUNT}/bin/x86/heroes3 ${GAMEDIR}
	${BRANDELF} -t Linux ${GAMEDIR}/heroes3
	${LN} -sf ${PREFIX}/${GAMESUBDIR}/heroes3 ${STAGEDIR}${PREFIX}/bin/heroes3
.for f in ${GAMEFILES}
	${INSTALL_DATA} ${CDROM_MOUNT}/${f} ${GAMEDIR}
.endfor
	${MKDIR} ${GAMEDIR}/data
	${TOUCH} ${GAMEDIR}/data/hiscore.dat
	${CHMOD} 666 ${GAMEDIR}/data/hiscore.dat
.for f in ${DATAFILES}
	${INSTALL_DATA} ${CDROM_MOUNT}/data/${f} ${GAMEDIR}/data
.endfor
	${MKDIR} ${GAMEDIR}/maps
	${INSTALL_DATA} ${CDROM_MOUNT}/maps/* ${GAMEDIR}/maps
	${MKDIR} ${GAMEDIR}/data/video
	${INSTALL_DATA} ${CDROM_MOUNT}/data/video/*.mjpg ${GAMEDIR}/data/video
	${INSTALL_DATA} ${CDROM_MOUNT}/data/video/credits.pcx ${GAMEDIR}/data/video
	${INSTALL_DATA} ${CDROM_MOUNT}/data/video/*.mpg ${GAMEDIR}/data/video
	${MKDIR} ${GAMEDIR}/mp3
	${INSTALL_DATA} ${CDROM_MOUNT}/mp3/* ${GAMEDIR}/mp3

.include <bsd.port.mk>
