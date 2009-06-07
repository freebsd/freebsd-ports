# New ports collection makefile for:	linux-coldwar-demo
# Date created:		2009-01-31
# Whom:			Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	coldwar-demo
PORTVERSION=	1.1
CATEGORIES=	games linux
MASTER_SITES=	http://demofiles.linuxgamepublishing.com/coldwar/
PKGNAMEPREFIX=	linux-
DISTNAME=	coldwar_demo
EXTRACT_SUFX=	.run

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Coldwar Demo - a third-person sneaker like Splinter Cell

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_LINUX_APPS=	sdl12 jpeg sdlmixer mikmod libogg libvorbis libtheora xorglibs
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	coldwar
PORTDOCS=	README README.licenses EULA

OPTIONS=	NVIDIA	"Install support for nvidia"	off

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver \
		${LINUXBASE}/usr/X11R6/lib/libGLU.so.1:${PORTSDIR}/graphics/linux-libGLU
.else
USE_LINUX_APPS+=dri
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} +377 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} jxf -
	@cd ${WRKSRC}/data && ${TAR} --exclude lib -xzf ${WRKSRC}/data/data.tar.gz

pre-configure:
	@${REINPLACE_CMD} -e \
		's|function version|version\(\)|; \
		s|function usage|usage\(\)|' \
		${WRKSRC}/data/bin/launcher

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/meng

do-install:
	@${MKDIR} ${DATADIR}/bin
	@cd ${WRKSRC}/bin/Linux/x86 && \
		${INSTALL_PROGRAM} bin/meng ${DATADIR}/bin
	@cd ${WRKSRC}/data/bin && \
		${INSTALL_PROGRAM} launcher ${DATADIR}/bin
	@${CP} -R ${WRKSRC}/data/config ${DATADIR}/
	@${CP} -R ${WRKSRC}/data/data ${DATADIR}/
	@${INSTALL_PROGRAM} ${WRKDIR}/coldwar ${PREFIX}/bin/${PKGNAMEPREFIX}coldwar
.if !defined (NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
