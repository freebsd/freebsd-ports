# New ports collection makefile for:    games
# Version required:	1.8
# Date created:         Mon Dec 14 21:03:01 MET 1998
# Whom:                 jmz
#
# $Id: Makefile,v 1.11 1999/02/10 03:52:47 jmz Exp $
#

DISTNAME=	doomsrc-1.8
PKGNAME=	doom-1.8
CATEGORIES=	games
MASTER_SITES?=	ftp://ftp.idsoftware.com/idstuff/source/ \
		ftp://ftp.stomped.com/pub/idmirror/idstuff/source/ \
		ftp://ftp.cdrom.com/pub/idgames/idstuff/source/ \
		ftp://ftp.gamesnet.net/idsoftware/source/
DISTFILES?=	doomsrc.zip

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_CDROM=	requested by IDsoftware

MASTER_SITES2=	ftp://sunsite.unc.edu/pub/Linux/games/doom/ \
		ftp://ftp.infomagic.com/pub/mirrors/linux/sunsite/games/doom/ \
		ftp://ftp.funet.fi/pub/mirrors/sunsite.unc.edu/pub/Linux/games/doom/
DISTFILES2=	doom1v18.wad.gz

USE_XLIB=	yes
EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-q
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes

.if !defined(__REAL_FETCH__)
do-fetch:
	@${MAKE} ${.MAKEFLAGS} do-fetch __REAL_FETCH__=YES
	@${MAKE} ${.MAKEFLAGS} do-fetch __REAL_FETCH__=YES \
	DISTFILES="${DISTFILES2}" MASTER_SITES="${MASTER_SITES2}"
.endif
post-extract:
	@cd ${WRKDIR} && tar xzf linuxdoom-1.10.src.tgz && tar xzf sndserv.tgz

do-build:
	@cd ${WRKDIR}/linuxdoom-1.10 && ${GMAKE}
	@cd ${WRKDIR}/sndserv && ${GMAKE}

do-install:
	@${MKDIR} ${PREFIX}/libexec/doom ${PREFIX}/share/doom
	@${INSTALL_PROGRAM} ${WRKDIR}/linuxdoom-1.10/linux/linuxxdoom ${PREFIX}/libexec/doom/xdoom
	@${INSTALL_PROGRAM} ${WRKDIR}/sndserv/linux/sndserver ${PREFIX}/libexec/doom/sndserver
	@(${ECHO} "#!/bin/sh"; ${ECHO} "cd ${PREFIX}/libexec/doom"; \
	  ${ECHO} 'export PATH=.:$$PATH';${ECHO} "export DOOMWADDIR=${PREFIX}/share/doom"; ${ECHO} "./xdoom $$*") > ${PREFIX}/bin/doom
	@/bin/chmod ugo+x ${PREFIX}/bin/doom
	@${GZCAT} ${DISTDIR}/${DISTFILES2} > ${PREFIX}/share/doom/doom1.wad

.include <bsd.port.mk>
