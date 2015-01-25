# $FreeBSD$

PORTNAME=	coldwar-demo
PORTVERSION=	1.1
CATEGORIES=	games linux
MASTER_SITES=	http://demofiles.linuxgamepublishing.com/coldwar/
PKGNAMEPREFIX=	linux-
DISTNAME=	coldwar_demo
EXTRACT_SUFX=	.run

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Coldwar Demo - a third-person sneaker like Splinter Cell

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	sdl12 jpeg sdlmixer openal mikmod libogg libvorbis libtheora xorglibs
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	coldwar
PORTDOCS=	README README.licenses EULA

OPTIONS_DEFINE=	NVIDIA DOCS
NVIDIA_DESC=	Enable nvidia graphics driver support

BROKEN=		Does not fetch

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
	@cd ${WRKSRC}/data && ${TAR} --exclude lib -xzf ${WRKSRC}/data/data.tar.gz

pre-configure:
	@${REINPLACE_CMD} -e \
		's|function version|version\(\)|; \
		s|function usage|usage\(\)|' \
		${WRKSRC}/data/bin/launcher

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/meng

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	@cd ${WRKSRC}/bin/Linux/x86 && \
		${INSTALL_PROGRAM} bin/meng ${STAGEDIR}${DATADIR}/bin
	@cd ${WRKSRC}/data/bin && \
		${INSTALL_PROGRAM} launcher ${STAGEDIR}${DATADIR}/bin
	@${CP} -R ${WRKSRC}/data/config ${STAGEDIR}${DATADIR}/
	@${CP} -R ${WRKSRC}/data/data ${STAGEDIR}${DATADIR}/
	@${INSTALL_PROGRAM} ${WRKDIR}/coldwar \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}coldwar
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
