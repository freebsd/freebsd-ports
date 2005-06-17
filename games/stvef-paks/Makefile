# New ports collection makefile for:    Star Trek Voyager: Elite Force paks
# Date created:				Sat Jul 15 14:27:16 SAST 2000
# Whom:					nik@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	stvef-paks
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	#
DISTFILES=	pak0.pk3
DIST_SUBDIR=	stvef
IGNOREFILES=	${ALLFILES}

MAINTAINER=	nik@FreeBSD.org
COMMENT=	Star Trek Voyager: Elite Forces dedicated server for Linux .pk3 files

# Make this a BUILD_DEPENDS too, so that it can create the
# directory hierarchy for us.
BUILD_DEPENDS=	${X11BASE}/games/stvef/linuxstvefded_1.2-static:${PORTSDIR}/games/stvef-server
RUN_DEPENDS=	${BUILD_DEPENDS}

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
EXTRACT_ONLY=	# Don't extract anything

GAMEDIR=	${PREFIX}/games/stvef/

.include <bsd.port.pre.mk>

# The only file we *must* have (I think) is pak0.pk3
.if !exists(${DISTDIR}/stvef/pak0.pk3)
IGNORE=You must manually copy all the files from the BaseEF directory of the original CD-ROM (or an installed version of the game) to the ${DISTDIR}/stvef directory and then run make again.
.endif

# Abuse the build target to generate ${PLIST}.  We can't have a fixed
# ${PLIST}, because the contents of the stvef directory will depend on which
# .pk3 files they copy over, and the patch level of the install they copied
# them from.  So assume that the user knows what they're doing, and blindly
# install everything (including non-.pk3 files, which might be necessary).
do-build:
	${RM} -f ${PLIST}
	for file in ${DISTDIR}/stvef/*; do				\
		b=`basename $$file`;					\
		${ECHO_CMD} games/stvef/baseEF/$$b >> ${PLIST};		\
	done

do-install:
	${MKDIR} ${GAMEDIR}/baseEF
	for file in ${DISTDIR}/stvef/*; do				\
		${INSTALL_DATA} $$file ${GAMEDIR}/baseEF;		\
	done

.include <bsd.port.post.mk>
