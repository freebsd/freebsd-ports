PORTNAME=	trigger-rally
PORTVERSION=	0.6.6.1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/trigger-rally/trigger-${PORTVERSION}

MAINTAINER=	alfix86@gmail.com
COMMENT=	Rally car racing game
WWW=		http://trigger-rally.sourceforge.net

LICENSE=	GPLv2
LICENSE_FILE=	${WORKINGSRC}/doc/COPYING.txt

LIB_DEPENDS=	libphysfs.so:devel/physfs
LIB_DEPENDS+=	libalut.so:audio/freealut
LIB_DEPENDS+=	libtinyxml2.so:textproc/tinyxml2

USES=		compiler:c++11-lang gmake openal:al,alut sdl gl gnome

USE_SDL=	image2
USE_GL=		glu glew
MAKEFILE=	GNUmakefile
ALL_TARGET=	build
LDFLAGS_i386=	-Wl,-znotext

WRKSRC_SUBDIR=	src
WORKINGSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
DATADIR=	${PREFIX}/share/games/trigger-rally

DESKTOP_ENTRIES="Trigger" "" "trigger" \
		"trigger-rally" "" false

PORTDOCS=	README-stereo.txt README.txt DATA_AUTHORS.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# The following is actually meant for lld 15.0 and later, but the ports
# framework does not support LINKER_TYPE and LINKER_VERSION yet.
.if ${COMPILER_TYPE} == "clang"
# Turn off checking of dynamic relocations, to avoid lld diagnostics about
# possibly incorrect addend values.
LDFLAGS_i386+=	-Wl,--no-check-dynamic-relocations
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Trigger/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WORKINGSRC}/bin/trigger-rally ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WORKINGSRC}/bin && ${CP} trigger-rally.config.defs ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WORKINGSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	cd ${WORKINGSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
.for i in 16 22 24 32 36 48 64 72 96 128 192 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/ && \
	${MV} ${STAGEDIR}${DATADIR}/icon/trigger-${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/trigger.png
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/ && \
	${MV} ${STAGEDIR}${DATADIR}/icon/trigger-rally-icons.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/trigger-rally-icons.svg

.include <bsd.port.post.mk>
