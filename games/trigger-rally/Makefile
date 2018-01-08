# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	trigger-rally
PORTVERSION=	0.6.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/trigger-rally/trigger-${PORTVERSION}

MAINTAINER=	alfix86@gmail.com
COMMENT=	Rally car racing game

LICENSE=	GPLv2

LIB_DEPENDS=	libphysfs.so:devel/physfs
LIB_DEPENDS+=	libalut.so:audio/freealut

#BROKEN_aarch64=		fails to compile: error: the clang compiler does not support -march=native
#BROKEN_armv6=		fails to compile: error: the clang compiler does not support -march=native
#BROKEN_armv7=		fails to compile: error: the clang compiler does not support -march=native
#BROKEN_powerpc64=	fails to compile: error: the clang compiler does not support -march=native

WRKSRC_SUBDIR=	src
USES=		gmake openal:al,alut
USE_SDL=	sdl2 image2
USE_GL=		glu gl glew
MAKEFILE=	GNUmakefile
ALL_TARGET=	build
LLD_UNSAFE=	yes

WORKINGSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
DATADIR=	${PREFIX}/share/games/trigger-rally

DESKTOP_ENTRIES="Trigger" "" "trigger" \
		"trigger-rally" "" false

PORTDOCS=	README-stereo.txt README.txt DATA_AUTHORS.txt

do-install:
	${INSTALL_PROGRAM} ${WORKINGSRC}/bin/trigger-rally ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WORKINGSRC}/bin && ${CP} trigger-rally.config.defs ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WORKINGSRC}/doc && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	cd ${WORKINGSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
.for i in 16 22 24 32 36 48 64 72 96 128 192 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/ && \
	${MV} ${STAGEDIR}${DATADIR}/icon/trigger-${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/trigger.png
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/ && \
	${MV} ${STAGEDIR}${DATADIR}/icon/trigger-rally-icons.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/trigger-rally-icons.svg

.include <bsd.port.mk>
