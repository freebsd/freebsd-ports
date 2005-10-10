# New ports collection makefile for:    games
# Date created:         Mon Dec 14 21:03:01 MET 1998
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	doom
PORTVERSION=	1.10
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/:src \
		ftp://ftp.stomped.com/pub/idmirror/idstuff/source/:src \
		ftp://ftp.cdrom.com/pub/idgames/idstuff/source/:src \
		${MASTER_SITE_SUNSITE:S/$/:wad/g}
MASTER_SITE_SUBDIR=	games/doom/:wad
DISTFILES=	${SRCFILE}:src ${WADFILE}:wad
EXTRACT_ONLY=	${SRCFILE}

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	DOOM: the game and the sound server

NO_CDROM=	requested by IDsoftware

WADFILE=	doom1v18.wad.gz
SRCFILE=	doomsrc${EXTRACT_SUFX}

ONLY_FOR_ARCHS=	i386

USE_XLIB=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes

post-extract:
	@cd ${WRKDIR} && ${TAR} xzf linuxdoom-1.10.src.tgz && ${TAR} xzf sndserv.tgz

do-build:
	@cd ${WRKDIR}/linuxdoom-1.10 && ${GMAKE}
	@cd ${WRKDIR}/sndserv && ${GMAKE}

do-install:
	@${MKDIR} ${PREFIX}/libexec/doom ${PREFIX}/share/doom
	@${INSTALL_PROGRAM} ${WRKDIR}/linuxdoom-1.10/linux/linuxxdoom ${PREFIX}/libexec/doom/xdoom
	@${INSTALL_PROGRAM} ${WRKDIR}/sndserv/linux/sndserver ${PREFIX}/libexec/doom/sndserver
	@(${ECHO_CMD} "#!/bin/sh"; ${ECHO_CMD} "cd ${PREFIX}/libexec/doom"; \
	  ${ECHO_CMD} 'export PATH=.:$$PATH';${ECHO_CMD} "export DOOMWADDIR=${PREFIX}/share/doom"; ${ECHO_CMD} "./xdoom $$*") > ${PREFIX}/bin/doom
	@${CHMOD} ugo+x ${PREFIX}/bin/doom
	@${GZCAT} ${DISTDIR}/${WADFILE} > ${PREFIX}/share/doom/doom1.wad

.include <bsd.port.mk>
