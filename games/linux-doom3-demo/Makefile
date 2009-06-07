# New ports collection makefile for:	doom3-demo
# Date created:			31 Mar 2005
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	doom3-demo
PORTVERSION=	1.1.1286
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://www.hup.hu/~trey/DOOM3/ \
		http://darkstar.ist.utl.pt/pub/games/ \
		ftp://ftp.headoff.com/GameDemos/Doom3/ \
		IDSOFTWARE/doom3/linux
PKGNAMEPREFIX=	linux-
DISTNAME=	doom3-linux-${PORTVERSION}-demo.x86
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DOOM III demo for Linux

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
NO_PACKAGE=	Distfile size is 462MB, set FORCE_PACKAGE if you really want to build this package
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DOOMDIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

SUB_FILES=	doom3-demo
SUB_LIST=	DOOMDIR="${DOOMDIR}"

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
USE_LINUX_APPS+=dri
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} -c +8767 ${_DISTDIR}/${DISTFILES} | ${TAR} zxf -

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/doom3-demo ${PREFIX}/bin/${PKGNAMEPREFIX}doom3-demo

	${MKDIR} ${DOOMDIR}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/demo00.pk4 ${DOOMDIR}/demo

	${INSTALL_PROGRAM} ${WRKSRC}/bin/Linux/x86/doom.x86 ${DOOMDIR}
.for f in gamex86.so
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOOMDIR}
	-${CHOWN} ${LIBOWN}:${LIBGRP} ${DOOMDIR}/${f}
	${CHMOD} ${LIBMODE} ${DOOMDIR}/${f}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in License.txt README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
