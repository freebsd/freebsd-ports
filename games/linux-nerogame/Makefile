# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nerogame
PORTVERSION=	2.0
CATEGORIES=	games linux
MASTER_SITES=	http://nn.cs.utexas.edu/nero/downloads/
PKGNAMEPREFIX=	linux-
DISTNAME=	nero2_linux_i386

MAINTAINER=	craig001@lerwick.hopto.org
COMMENT=	Neuro evolving robotic operatives the game

USE_LINUX=	yes
USE_LINUX_APPS=	libvorbis sdl12 libtheora
NO_BUILD=	yes
RESTRICTED=	Nero is freeware, but i am not sure of its license

SUB_FILES=	nerogame pkg-message
DATADIR=	share/${PKGNAMEPREFIX}${PORTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=	NVIDIA
NVIDIA_DESC=	Nvidia support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNVIDIA}
.	if !exists(${LINUXBASE}/usr/lib/libGL.so.1)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver
.	endif
.else
USE_LINUX_APPS+=dri
.endif

do-install:
	${BRANDELF} -t Linux ${WRKSRC}/nero.bin
	${INSTALL_PROGRAM} ${WRKSRC}/nero.bin ${STAGEDIR}${PREFIX}/libexec/${PKGNAMEPREFIX}${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}

	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/libopenal.so ${STAGEDIR}${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}

.for DIRE in common nero
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DATADIR}/${DIRE}
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/${DATADIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${PREFIX}/${DATADIR}/${DIRE}/{}" \;
.endfor
	${INSTALL_DATA} ${WRKSRC}/main.cs ${STAGEDIR}${PREFIX}/${DATADIR}

	@${MKDIR} ${STAGEDIR}${PREFIX}/${DATADIR}/lib
	${LN} -s ${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}/libopenal.so ${STAGEDIR}${PREFIX}/${DATADIR}/lib/libopenal.so

.include <bsd.port.mk>
