# Created by: Marcus von Appen <mva@sysfault.org>
# $FreeBSD$

PORTNAME=	uplink-demo
PORTVERSION=	1.55
CATEGORIES=	games linux
MASTER_SITES=	http://www.introversion.co.uk/uplink/downloads/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION}DEMO
EXTRACT_SUFX=	.sh

MAINTAINER=	mva@FreeBSD.org
COMMENT=	High tech computer crime and industrial espionage on the Internet

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	sdl12 jpeg sdlmixer mikmod libvorbis xorglibs
USE_LDCONFIG=	yes
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	uplink
SUB_LIST=	LINUXBASE=${LINUXBASE}
DOCFILES=	license.txt mods.txt Readme-UplinkSupport.txt readme.txt

OPTIONS_DEFINE=	NVIDIA DOCS
NVIDIA_DESC=	support for nvidia

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNVIDIA}
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver
USE_LINUX_APPS+=libglu
.else
USE_LINUX_APPS+=dri
.endif

do-extract:
	@cd ${WRKSRC} && ${TAIL} +376 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/lib/uplink.bin.x86

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/lib && \
		${INSTALL_PROGRAM} uplink.bin.x86 libftgl.so.0 ${STAGEDIR}${DATADIR} && \
		${INSTALL_DATA} *.dat ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/uplink \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}uplink
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}/${file}
.endfor

.include <bsd.port.mk>
