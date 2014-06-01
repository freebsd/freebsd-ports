# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nerogame
PORTVERSION=	2.0
CATEGORIES=	games linux
MASTER_SITES=	http://z.cs.utexas.edu/users/nn/nero/downloads/
PKGNAMEPREFIX=	linux-
DISTNAME=	nero2_linux_i386

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Neuro evolving robotic operatives the game

BROKEN=		Unfetchable

USE_LINUX=	yes
USE_LINUX_APPS=	libvorbis sdl12 libtheora
NO_BUILD=	yes
RESTRICTED=	Nero is freeware, but i am not sure of its license

SUB_FILES=	nerogame pkg-message
DATADIR=	share/${PKGNAMEPREFIX}${PORTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=	NVIDIA
NVIDIA_DESC=	Nvidia support

NO_STAGE=	yes
.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800076
BROKEN=		does not build
.endif

.if ${PORT_OPTIONS:MNVIDIA}
.	if !exists(${LINUXBASE}/usr/lib/libGL.so.1)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.	endif
.else
USE_LINUX_APPS+=dri
.endif

do-install:
	${BRANDELF} -t Linux ${WRKSRC}/nero.bin
	${INSTALL_PROGRAM} ${WRKSRC}/nero.bin ${PREFIX}/libexec/${PKGNAMEPREFIX}${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}

	@${MKDIR} ${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/libopenal.so ${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}

.for DIRE in common nero
	@${MKDIR} ${PREFIX}/${DATADIR}/${DIRE}
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${DATADIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/${DATADIR}/${DIRE}/{}" \;
.endfor
	${INSTALL_DATA} ${WRKSRC}/main.cs ${PREFIX}/${DATADIR}

	@${MKDIR} ${PREFIX}/${DATADIR}/lib
	${LN} -s ${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}/libopenal.so ${PREFIX}/${DATADIR}/lib/libopenal.so

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
