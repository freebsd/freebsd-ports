# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	marsnomercy
PORTVERSION=	0.2.1
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF/mars/mars/${PORTVERSION}
DISTNAME=	mars-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Turn-based strategy game setting on Mars

LICENSE=	GPLv2 # version unspecified actually

BUILD_DEPENDS=	scons:devel/scons

USE_GL=		gl
USE_SDL=	sdl image ttf
SCONS_ARGS=	prefix=${PREFIX}

SUB_FILES=	mars-nomercy pkg-message
WRKSRC=		${WRKDIR}/mars-${PORTVERSION}

PLIST_FILES=	bin/mars-nomercy \
		libexec/mars
PLIST_DIRS=	%%DATADIR%%/img/units/mercenaries
PORTDATA=	*

OPTIONS_DEFINE=	DEBUG OPENGL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
SCONS_ARGS+=	debug=1
.else
SCONS_ARGS+=	debug=0
.endif

.if ${PORT_OPTIONS:MOPENGL}
SCONS_ARGS+=	with_opengl=1
.else
SCONS_ARGS+=	with_opengl=0
.endif

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} scons ${SCONS_ARGS}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mars-nomercy ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/mars ${STAGEDIR}${PREFIX}/libexec/mars
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	@${RM} -f ${STAGEDIR}${DATADIR}/SConscript

.include <bsd.port.mk>
