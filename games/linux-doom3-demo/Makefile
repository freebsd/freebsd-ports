# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

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
NO_CDROM=	Redistribution is limited, see license; Requested by id Software
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DOOMDIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

SUB_FILES=	doom3-demo
SUB_LIST=	DOOMDIR="${DOOMDIR}"

OPTIONS_DEFINE=	DOCS NVIDIA_GL

NVIDIA_GL_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver
NVIDIA_GL_USE_OFF=	linux_apps=dri


do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} -c +8767 ${_DISTDIR}/${DISTFILES} | ${TAR} zxf -

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/doom3-demo ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}doom3-demo
	${MKDIR} ${STAGEDIR}${DOOMDIR}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/demo00.pk4 ${STAGEDIR}${DOOMDIR}/demo
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Linux/x86/doom.x86 ${STAGEDIR}${DOOMDIR}
.for f in gamex86.so
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOOMDIR}
	-${CHOWN} ${LIBOWN}:${LIBGRP} ${STAGEDIR}${DOOMDIR}/${f}
	${CHMOD} ${LIBMODE} ${STAGEDIR}${DOOMDIR}/${f}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in License.txt README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
