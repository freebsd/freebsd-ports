# New ports collection makefile for:    Quake 3 paks
# Date created:				1st March 2003
# Whom:					nik@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	q3-paks
PORTVERSION=	1.0
CATEGORIES=	games linux
MASTER_SITES=	#
DISTFILES=	pak0.pk3
DIST_SUBDIR=	q3-paks
IGNOREFILES=	${ALLFILES}

MAINTAINER=	nik@FreeBSD.org
COMMENT=	Quake 3 for Linux .pk3 files

# Make this a BUILD_ rather than a RUN_DEPEND so that it can create the
# directory hierarchy for us.
RUN_DEPENDS=	${LINUXBASE}/usr/games/quake3/q3ded:${PORTSDIR}/games/q3server

PLIST_FILES=	usr/games/quake3/baseq3/pak0.pk3
ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
EXTRACT_ONLY=	# Don't extract anything
STRIP=

GAMEDIR=	${PREFIX}/usr/games/quake3/

.include <bsd.port.pre.mk>

.for file in ${DISTFILES}
.if !exists(${DISTDIR}/q3-paks/${file})
IGNORE=You must manually copy all the .pk3 files from the baseq3/ directory of an installed version of the game to the ${DISTDIR}/q3-paks directory and then run make again.
.endif
.endfor

# Do nothing for the build.  Don't set NO_BUILD because of the earlier
# BUILD_DEPENDS
do-build:

do-install:
	${MKDIR} ${GAMEDIR}/baseq3
.for file in ${DISTFILES}
	${INSTALL_DATA} ${DISTDIR}/q3-paks/${file} ${GAMEDIR}/baseq3
.endfor

.include <bsd.port.post.mk>
