# Created by: Marcus von Appen <mva@sysfault.org
# $FreeBSD$

PORTNAME=	defcon
PORTVERSION=	1.42
CATEGORIES=	games linux
MASTER_SITES=	http://download.introversion.co.uk/defcon/linux/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Defcon for Linux

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	sdl12 libogg libvorbis xorglibs
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	defcon

OPTIONS_DEFINE=	NVIDIA DOCS
NVIDIA_DESC=	support for nvidia

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNVIDIA}
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver
USE_LINUX_APPS+=libglu
.else
USE_LINUX_APPS+=dri
.endif

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/lib/defcon.bin.x86

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/lib && \
		${INSTALL_PROGRAM} defcon.bin.x86 ${STAGEDIR}${DATADIR} && \
		${INSTALL_DATA} *.dat open-www.sh ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/defcon \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}defcon
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${STAGEDIR}${DOCSDIR}/license.txt
	${INSTALL_DATA} ${WRKSRC}/manual.pdf ${STAGEDIR}${DOCSDIR}/manual.pdf

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
