# New ports collection makefile for:	linux-gorky17-demo
# Date created:		2009-02-01
# Whom:			Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	gorky17-demo
PORTVERSION=	1.0.1
CATEGORIES=	games linux
MASTER_SITES=	http://demofiles.linuxgamepublishing.com/gorky17/
PKGNAMEPREFIX=	linux-
DISTNAME=	gorky17_demo
EXTRACT_SUFX=	.run

MAINTAINER=	mva@sysfault.org
COMMENT=	Gorky17 Demo - a tactical shooter similiar to Jagged Alliance

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12 \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libSDL_mixer-1.2.so.0:${PORTSDIR}/audio/linux-sdl_mixer \
		${LINUXBASE}/usr/lib/libmikmod.so.2:${PORTSDIR}/audio/linux-mikmod \
		${LINUXBASE}/usr/lib/libogg.so.0:${PORTSDIR}/audio/linux-libogg \
		${LINUXBASE}/usr/lib/libvorbis.so.0:${PORTSDIR}/audio/linux-libvorbis

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_XLIB=	yes
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	gorky17
PORTDOCS=	README README.licenses EULA
DATFILES=	adjust.dat demo1.jpg demo2.jpg demo3.jpg

OPTIONS=	NVIDIA	"Install support for nvidia"	off

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver \
		${LINUXBASE}/usr/X11R6/lib/libGLU.so.1:${PORTSDIR}/graphics/linux-libGLU
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} +377 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} jxf -
	@cd ${WRKSRC}/data && ${TAR} -xzf ${WRKSRC}/data/data.tar.gz

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/gorky17_demo
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/gorky17_demo.dynamic

do-install:
	@${MKDIR} ${DATADIR}/bin
	@cd ${WRKSRC}/bin/Linux/x86 && \
		${INSTALL_PROGRAM} gorky17_demo gorky17_demo.dynamic ${DATADIR}/bin
	@${CP} -R ${WRKSRC}/data/avi ${DATADIR}/
	@${CP} -R ${WRKSRC}/data/dat ${DATADIR}/
.for file in ${DATFILES}
	@${INSTALL_DATA} ${WRKSRC}/data/${file} ${DATADIR}/${file}
.endfor
	@${INSTALL_PROGRAM} ${WRKDIR}/gorky17 ${PREFIX}/bin/${PKGNAMEPREFIX}gorky17
.if !defined (NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
