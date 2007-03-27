# New ports collection makefile for:	Alien Arena 2006
# Date created:		2005-11-12
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	alienarena
PORTVERSION=	2007.604
PORTEPOCH=	1
CATEGORIES=	games linux
MASTER_SITES=	http://cor.planetquake.gamespy.com/codered/files/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}2007-linux20070225-x86

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Alien Arena 2006 (Linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12 \
		${DATADIR}/arena/default.cfg:${PORTSDIR}/games/alienarena-data

USE_ZIP=	yes
USE_LINUX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:C/-linux.*//}

SUB_FILES=	linux-alienarena linux-alienarena-ded
SUB_LIST=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}

DESKTOP_ENTRIES="Alien Arena 2006 (Linux version)" \
		"Play Alien Arena 2006 (Linux version)" \
		"alienarena.xpm" \
		"linux-alienarena" \
		"Application;Game;" \
		false

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver \
		${LINUXBASE}/usr/X11R6/lib/libGLU.so.1:${PORTSDIR}/graphics/linux-libGLU
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGLU.so.1:${PORTSDIR}/graphics/linux_dri
.endif

do-install:
	${MKDIR} ${LIBDIR}/arena ${LIBDIR}/data1
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} arena/gamei386.so ${LIBDIR}/arena && \
		${INSTALL_PROGRAM} data1/gamei386.so ${LIBDIR}/data1
	${LN} -sf ${DATADIR}/arena/* ${LIBDIR}/arena
	${LN} -sf ${DATADIR}/botinfo ${LIBDIR}
	${LN} -sf ${DATADIR}/data1/* ${LIBDIR}/data1
.for f in crx.sdl crded
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${LIBDIR}
.endfor
.for f in linux-alienarena linux-alienarena-ded
	${INSTALL_SCRIPT} ${WRKDIR}/${f} ${PREFIX}/bin
.endfor

.include <bsd.port.post.mk>
