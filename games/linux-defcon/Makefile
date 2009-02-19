# New ports collection makefile for:	linux-defcon
# Date created:				24 May 2007
# Whom:					Marcus von Appen <mva@sysfault.org
#
# $FreeBSD$
#

PORTNAME=	defcon
PORTVERSION=	1.42
CATEGORIES=	games linux
MASTER_SITES=	http://download.introversion.co.uk/defcon/linux/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Defcon for Linux

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12 \
		${LINUXBASE}/usr/lib/libogg.so.0:${PORTSDIR}/audio/linux-libogg \
		${LINUXBASE}/usr/lib/libvorbisfile.so.3:${PORTSDIR}/audio/linux-libvorbis

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_XLIB=	yes
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	defcon

OPTIONS=	NVIDIA	"Install support for nvidia"	off

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver \
		${LINUXBASE}/usr/X11R6/lib/libGLU.so.1:${PORTSDIR}/graphics/linux-libGLU
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/lib/defcon.bin.x86

do-install:
	${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/lib && \
		${INSTALL_PROGRAM} defcon.bin.x86 ${DATADIR} && \
		${INSTALL_DATA} *.dat open-www.sh ${DATADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/defcon ${PREFIX}/bin/${PKGNAMEPREFIX}defcon
.if !defined (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}/license.txt
	${INSTALL_DATA} ${WRKSRC}/manual.pdf ${DOCSDIR}/manual.pdf
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
