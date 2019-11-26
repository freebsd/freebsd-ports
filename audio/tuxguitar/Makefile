# Created by: Pietro Cerutti (gahr@gahr.ch)
# $FreeBSD$

PORTNAME=	tuxguitar
PORTVERSION=	1.2
PORTREVISION=	15
CATEGORIES=	audio java
MASTER_SITES=	SF/${PORTNAME}/TuxGuitar/TuxGuitar-${PORTVERSION}:src \
		LOCAL/gahr/:fluid \
		http://people.freebsd.org/~gahr/distfiles/:fluid \
		http://www.alsa-project.org/~james/sound-fonts/:fluid
DISTNAME=	${PORTNAME}-src-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		8MBGMSFX.SF2:fluid
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multitrack tablature editor and player

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${JAVALIBDIR}/swt.jar:x11-toolkits/swt \
		${JAVALIBDIR}/itext.jar:devel/itext \
		${JAVALIBDIR}/gervill.jar:audio/gervill
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth \
		libjack.so:audio/jack

MAKE_ENV+=	PREFIX=${PREFIX} INSTALL_DOC_DIR=${DOCSDIR} \
		INSTALL_SHARE_DIR=${DATADIR}

USES=		cpe desktop-file-utils gmake pkgconfig
CPE_VENDOR=	herac
USE_JAVA=	yes
USE_ANT=	yes
USE_LDCONFIG=	yes
NO_CCACHE=	yes

BUILD_WRKSRC=	${WRKSRC}/TuxGuitar
SF2_DIR=	${LOCALBASE}/share/sounds/sf2

OPTIONS_DEFINE=	DOCS

PLUGINS=	ascii compat converter fluidsynth gervill gtp \
		jsa lilypond midi musicxml oss pdf ptb tef tray tuner

SUB_FILES=	pkg-message tuxguitar
SUB_LIST=	DATADIR=${DATADIR} \
		PREFIX=${PREFIX} \
		JAVALIBDIR=${JAVALIBDIR} \
		SF2_DIR=${SF2_DIR}

post-extract:
	@${CP} ${DISTDIR}/8MBGMSFX.SF2 ${WRKDIR}

post-patch:
	@${FIND} ${WRKSRC} -name build.properties | ${XARGS} ${REINPLACE_CMD} -e '\
	    s|path\.swt=.*|path.swt=${JAVAJARDIR}/swt.jar|; \
	    s|path\.itext=.*|path.itext=${JAVAJARDIR}/itext.jar|; \
	    s|path\.gervill=.*|path.gervill=${JAVAJARDIR}/gervill.jar|'
	@${FIND} ${WRKSRC} -name GNUmakefile | ${XARGS} ${REINPLACE_CMD} -e '\
	    s|-I$$(shell gcj -print-file-name=include/)|-I${JAVA_HOME}/include \
	    -I${JAVA_HOME}/include/freebsd -I${LOCALBASE}/include|; \
	    s|-I $$(shell $$(GCJ) -print-file-name=include/)|-I${JAVA_HOME}/include \
	    -I${JAVA_HOME}/include/freebsd -I${LOCALBASE}/include|; \
	    s|LDFLAGS\?=.*|LDFLAGS+=-L${LOCALBASE}/lib|; \
	    s|CFLAGS\?=|CFLAGS+=|'
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g; \
	    s|%%PREFIX%%|${PREFIX}|g; \
	    s|%%JAVAJARDIR%%|${JAVAJARDIR}|g; \
	    s|%%JAVASHAREDIR%%|${JAVASHAREDIR}|g; \
	    s|%%DATADIR%%|${DATADIR}|g; \
	    s|%%DOCSDIR%%|${DOCSDIR}|g' \
	    ${WRKSRC}/TuxGuitar/build.properties

post-build:
.for p in ${PLUGINS}
	(cd ${WRKSRC}/TuxGuitar-${p}; \
	    ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} ${ALL_TARGET})
.endfor
	cd ${WRKSRC}/TuxGuitar-oss/jni && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}
	cd ${WRKSRC}/TuxGuitar-fluidsynth/jni && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}
	cd ${WRKSRC}/TuxGuitar-jack/jni && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tuxguitar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/TuxGuitar-oss/jni/libtuxguitar-oss-jni.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/TuxGuitar-fluidsynth/jni/libtuxguitar-fluidsynth-jni.so ${STAGEDIR}${PREFIX}/lib

	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/TuxGuitar/tuxguitar.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/misc/*.tg ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/8MBGMSFX.SF2 ${STAGEDIR}${DATADIR}
.for p in ${PLUGINS}
	${INSTALL_DATA} ${WRKSRC}/TuxGuitar-${p}/tuxguitar-${p}.jar ${STAGEDIR}${DATADIR}/plugins
.endfor
	# Inline documentation
	cd ${WRKSRC}/TuxGuitar/share/help &&   ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/help
	cd ${WRKSRC}/TuxGuitar/share/lang &&   ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/lang
	cd ${WRKSRC}/TuxGuitar/share/scales && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/scales
	cd ${WRKSRC}/TuxGuitar/share/skins &&  ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/skins

	${INSTALL_DATA} ${WRKSRC}/misc/tuxguitar.xpm ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/misc/tuxguitar.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/misc/tuxguitar.1 ${STAGEDIR}${MANPREFIX}/man/man1

	# Share soundfont with FluidSynth
	@${MKDIR} ${STAGEDIR}${SF2_DIR}
	${RLN} ${STAGEDIR}${DATADIR}/8MBGMSFX.SF2 ${STAGEDIR}${SF2_DIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/TuxGuitar/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
