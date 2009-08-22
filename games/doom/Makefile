# New ports collection makefile for:    games
# Date created:         Mon Dec 14 21:03:01 MET 1998
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	doom
PORTVERSION=	1.10
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	# none known, please fix
DISTNAME=	doomsrc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DOOM: the game and the sound server

NO_CDROM=	requested by IDsoftware

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes
USE_ZIP=	yes
USE_XORG=	x11 sm xextproto xext
NO_WRKSUBDIR=	yes

DATADIR=	${DMDIR}

post-extract:
	@cd ${WRKDIR} && ${TAR} xzf linuxdoom-1.10.src.tgz && ${TAR} xzf sndserv.tgz

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} \
		-E -e 's|#include +<malloc.h>|#include <stdlib.h>|g'

do-build:
	@cd ${WRKDIR}/linuxdoom-1.10 && ${GMAKE} X11BASE=${LOCALBASE}
	@cd ${WRKDIR}/sndserv && ${GMAKE}

do-install:
	@${MKDIR} ${PREFIX}/libexec/doom
	@${INSTALL_PROGRAM} ${WRKDIR}/linuxdoom-1.10/linux/linuxxdoom ${PREFIX}/libexec/doom/xdoom
	@${INSTALL_PROGRAM} ${WRKDIR}/sndserv/linux/sndserver ${PREFIX}/libexec/doom/sndserver
	@(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD} "cd ${PREFIX}/libexec/doom"; \
	  ${ECHO_CMD} 'export PATH=.:$$PATH';${ECHO_CMD} "export DOOMWADDIR=${DATADIR}"; ${ECHO_CMD} "./xdoom $$*") > ${PREFIX}/bin/doom
	@${CHMOD} ugo+x ${PREFIX}/bin/doom

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
