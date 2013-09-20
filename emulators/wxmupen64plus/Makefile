# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wxmupen64plus
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://cdn.bitbucket.org/auria/wxmupen64plus/downloads/
DIST_SUBDIR=	${PORTNAME:S/wx//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A Mupen64Plus 2.0 GUI frontend written using wxWidgets

LIB_DEPENDS=	mupen64plus.2:${PORTSDIR}/emulators/mupen64plus-core
RUN_DEPENDS=	${LOCALBASE}/lib/libmupen64plus.so.2:${PORTSDIR}/emulators/mupen64plus-core \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-audio-sdl.so:${PORTSDIR}/emulators/mupen64plus-audio-sdl \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-input-sdl.so:${PORTSDIR}/emulators/mupen64plus-input-sdl \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-rsp-hle.so:${PORTSDIR}/emulators/mupen64plus-rsp-hle \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-video-rice.so:${PORTSDIR}/emulators/mupen64plus-video-rice \
		mupen64plus:${PORTSDIR}/emulators/mupen64plus-ui-console

USE_ZIP=	yes
USE_SDL=	yes
USE_WX=		2.9
WX_UNICODE=	yes
USE_PYTHON=	yes

WAF_SCRIPT=	waf

NO_STAGE=	yes
do-configure:
	@cd ${WRKSRC} && \
		${PYTHON_CMD} ${WAF_SCRIPT} configure --mupenapi=${LOCALBASE}/include/${PORTNAME:S/wx//} \
				--wxconfig=${WX_CONFIG} \
				--sdlconfig=${SDL_CONFIG} \
				--datadir=${DATADIR} \
				--libdir=${LOCALBASE}/lib/${PORTNAME:S/wx//}

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${WAF_SCRIPT}

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/build/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
