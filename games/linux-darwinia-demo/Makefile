# New ports collection makefile for:	linux-darwinia
# Date created:				24 May 2007
# Whom:					Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	darwinia-demo
PORTVERSION=	1.3.0
CATEGORIES=	games linux
MASTER_SITES=	http://download.introversion.co.uk/mirror/introversion/darwinia/downloads/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}2-${PORTVERSION}
EXTRACT_SUFX=	.sh

MAINTAINER=	mva@sysfault.org
COMMENT=	Real-time action strategy with programs

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12 \
		${LINUXBASE}/usr/lib/libogg.so.0:${PORTSDIR}/audio/linux-libogg \
		${LINUXBASE}/usr/lib/libvorbisfile.so.3:${PORTSDIR}/audio/linux-libvorbis

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_XLIB=	yes
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	darwinia

OPTIONS=	NVIDIA	"Install support for nvidia"	off

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver \
		${LINUXBASE}/usr/X11R6/lib/libGLU.so.1:${PORTSDIR}/graphics/linux-libGLU
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAIL} +376 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/lib/darwinia.bin.x86

do-install:
	${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/lib && \
		${INSTALL_PROGRAM} darwinia.bin.x86 ${DATADIR} && \
		${INSTALL_DATA} *.dat open-www.sh ${DATADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/darwinia ${PREFIX}/bin/${PKGNAMEPREFIX}darwinia
.if !defined (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}/LICENSE
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
