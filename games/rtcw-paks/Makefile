# New ports collection makefile for:    Return to Castle Wolfenstein paks
# Date created:				Sat Jul 15 14:27:16 SAST 2000
# Whom:					nik@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rtcw-paks
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	#
DISTFILES=	mp_pak0.pk3 mp_pak1.pk3 mp_pak2.pk3 \
		pak0.pk3 \
		sp_pak1.pk3 sp_pak2.pk3
DIST_SUBDIR=	rtcw-paks
IGNOREFILES=	${ALLFILES}

MAINTAINER=	nik@FreeBSD.org
COMMENT=	Return to Castle Wolfenstein for Linux .pk3 files

# Make this a BUILD_DEPENDS too, so that it can create the 
# directory hierarchy for us.
BUILD_DEPENDS=	${X11BASE}/games/rtcw/wolf.x86:${PORTSDIR}/games/rtcw
RUN_DEPENDS=	${BUILD_DEPENDS}

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
EXTRACT_ONLY=	# Don't extract anything

GAMEDIR=	${PREFIX}/games/rtcw/

.include <bsd.port.pre.mk>

.for file in ${DISTFILES}
.if !exists(${DISTDIR}/rtcw-paks/${file})
IGNORE=You must manually copy all the .pk3 files from the main/ directory of an installed version of the game to the ${DISTDIR}/rtcw-paks directory and then run make again.
.endif
.endfor

# Do nothing for the build.  Don't set NO_BUILD because of the earlier 
# BUILD_DEPENDS
do-build:
	@${DO_NADA}

do-install: 
	${MKDIR} -p ${GAMEDIR}/main
.for file in ${DISTFILES}
	${INSTALL_DATA} ${DISTDIR}/rtcw-paks/${file} ${GAMEDIR}/main
.endfor

.include <bsd.port.post.mk>
