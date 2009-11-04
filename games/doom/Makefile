# New ports collection makefile for:    games
# Date created:         Mon Dec 14 21:03:01 MET 1998
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	doom
PORTVERSION=	1.10
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|source/|}
DISTNAME=	doomsrc

MAINTAINER=	chris@officialunix.com
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
	${REINPLACE_CMD} 's|<linux/soundcard.h>|<sys/soundcard.h>|g'\
			${WRKSRC}/sndserv/linux.c \
			${WRKSRC}/linuxdoom-1.10/i_sound.c
	${REINPLACE_CMD} 's|<errnos.h>|<errno.h>|g' \
			${WRKSRC}/linuxdoom-1.10/i_video.c
	${REINPLACE_CMD} 's|#include  <alloca.h>|//#include  <alloca.h>|g'\
			${WRKSRC}/linuxdoom-1.10/r_data.c
	${REINPLACE_CMD} 's|#include <alloca.h>|//#include <alloca.h>|g'\
			${WRKSRC}/linuxdoom-1.10/w_wad.c
	${REINPLACE_CMD} 's|<malloc.c>|<stdlib.h>|g'\
			${WRKSRC}/linuxdoom-1.10/w_wad.c \
			${WRKSRC}/sndserv/soundsrv.c \
			${WRKSRC}/sndserv/wadread.c
	${REINPLACE_CMD} 's|<values.h>|<limits.h>|g'\
			${WRKSRC}/linuxdoom-1.10/m_bbox.h \
			${WRKSRC}/linuxdoom-1.10/doomtype.h
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g'\
			${WRKSRC}/linuxdoom-1.10/Makefile
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
