# New ports collection makefile for:	Alien Arena 2006
# Date created:		2005-11-12
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	alienarena
DISTVERSION=	2006.ge
PORTEPOCH=	1
CATEGORIES=	games linux
MASTER_SITES=	http://offload1.icculus.org/~ravage/alienarena2006/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${DISTVERSION:S/.//}-i386

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Alien Arena 2006 (Linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libGLU.so.1.3:${PORTSDIR}/graphics/linux_dri \
		${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12 \
		${DATADIR}/arena/default.cfg:${PORTSDIR}/games/alienarena-data

.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.endif

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
USE_LINUX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	linux-alienarena linux-alienarena-ded
SUB_LIST=	LIBDIR=${LIBDIR}
PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

LIBDIR=		${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}

DESKTOP_ENTRIES="Alien Arena 2006 (Linux version)" \
		"Play Alien Arena 2006 (Linux version)" \
		"alienarena.xpm" \
		"linux-alienarena" \
		"Application;Game;" \
		false

.include <bsd.port.pre.mk>

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
