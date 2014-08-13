# $FreeBSD: head/games/linux-gorky17-demo/Makefile 340092 2014-01-17 18:09:49Z mva $

PORTNAME=	gorky17-demo
PORTVERSION=	1.0.1
CATEGORIES=	games linux
MASTER_SITES=	http://demofiles.linuxgamepublishing.com/gorky17/
PKGNAMEPREFIX=	linux-
DISTNAME=	gorky17_demo
EXTRACT_SUFX=	.run

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Tactical shooter similar to Jagged Alliance

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	sdl12 jpeg sdlmixer mikmod libogg libvorbis xorglibs
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	gorky17
PORTDOCS=	README README.licenses EULA
DATFILES=	adjust.dat demo1.jpg demo2.jpg demo3.jpg

OPTIONS_DEFINE=	NVIDIA DOCS
NVIDIA_DESC=	Enable nvidia graphics driver support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNVIDIA}
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
USE_LINUX_APPS+=libglu
.else
USE_LINUX_APPS+=dri
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
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	@cd ${WRKSRC}/bin/Linux/x86 && \
		${INSTALL_PROGRAM} gorky17_demo gorky17_demo.dynamic \
		${STAGEDIR}${DATADIR}/bin
	@${CP} -R ${WRKSRC}/data/avi ${STAGEDIR}${DATADIR}/
	@${CP} -R ${WRKSRC}/data/dat ${STAGEDIR}${DATADIR}/
.for file in ${DATFILES}
	@${INSTALL_DATA} ${WRKSRC}/data/${file} ${STAGEDIR}${DATADIR}/${file}
.endfor
	@${INSTALL_PROGRAM} ${WRKDIR}/gorky17 \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}gorky17
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
