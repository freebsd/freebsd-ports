# New ports collection makefile for:    games
# Date created:         Mon Dec 14 21:03:01 MET 1998
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	doom
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES?=	ftp://ftp.idsoftware.com/idstuff/source/ \
		ftp://ftp.stomped.com/pub/idmirror/idstuff/source/ \
		ftp://ftp.cdrom.com/pub/idgames/idstuff/source/
DISTNAME=	doomsrc

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	DOOM: the game and the sound server

NO_CDROM=	requested by IDsoftware

MASTER_SITES2=	ftp://sunsite.unc.edu/pub/Linux/games/doom/ \
		ftp://ftp.infomagic.com/pub/mirrors/linux/sunsite/games/doom/ \
		ftp://ftp.funet.fi/pub/mirrors/sunsite.unc.edu/pub/Linux/games/doom/
DISTFILES2=	doom1v18.wad.gz

ONLY_FOR_ARCHS=	i386

USE_PERL5_BUILD=yes
USE_XLIB=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes

.if !defined(__REAL_FETCH__)
do-fetch:
	@${MAKE} ${.MAKEFLAGS} do-fetch __REAL_FETCH__=YES
	@${MAKE} ${.MAKEFLAGS} do-fetch __REAL_FETCH__=YES \
	DISTFILES="${DISTFILES2}" MASTER_SITES="${MASTER_SITES2}"
.endif
post-extract:
	@cd ${WRKDIR} && ${TAR} xzf linuxdoom-1.10.src.tgz && ${TAR} xzf sndserv.tgz

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e "s@#include +<malloc.h>@#include <stdlib.h>@g"

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
	@${GZCAT} ${DISTDIR}/${DISTFILES2} > ${PREFIX}/share/doom/doom1.wad

.include <bsd.port.mk>
