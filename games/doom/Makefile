# Created by: Jean-Marc Zucconi <jmz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	doom
PORTVERSION=	1.10
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	IDSOFTWARE/source
DISTNAME=	doomsrc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DOOM: the game and the sound server

LICENSE=	IDSOFTWARE
LICENSE_NAME=	ID SOFTWARE LICENSE
LICENSE_FILE=	${WRKSRC}/linuxdoom-${PORTVERSION}/DOOMLIC.TXT
LICENSE_PERMS=	dist-mirror pkg-mirror

NO_CDROM=	Redistribution is limited, see license; Requested by id Software

ONLY_FOR_ARCHS=	i386

USES=		gmake xorg zip
USE_XORG=	x11 sm xorgproto xext
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
	@cd ${WRKDIR}/linuxdoom-1.10 && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} X11BASE=${LOCALBASE}
	@cd ${WRKDIR}/sndserv && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/doom
	${INSTALL_PROGRAM} ${WRKDIR}/linuxdoom-1.10/linux/linuxxdoom \
		${STAGEDIR}${PREFIX}/libexec/doom/xdoom
	${INSTALL_PROGRAM} ${WRKDIR}/sndserv/linux/sndserver \
		${STAGEDIR}${PREFIX}/libexec/doom/sndserver
	@(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD} "cd ${PREFIX}/libexec/doom"; \
	  ${ECHO_CMD} 'export PATH=.:$$PATH';${ECHO_CMD} "export DOOMWADDIR=${DATADIR}"; \
	  ${ECHO_CMD} "./xdoom $$*") > ${STAGEDIR}${PREFIX}/bin/doom
	@${CHMOD} ugo+x ${STAGEDIR}${PREFIX}/bin/doom

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
