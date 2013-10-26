# Created by: Pietro Cerutti (gahr@gahr.ch)
# $FreeBSD$

PORTNAME=	tuxguitar
PORTVERSION=	1.2
PORTREVISION=	7
CATEGORIES=	audio java
MASTER_SITES=	SF/${PORTNAME}/TuxGuitar/TuxGuitar-${PORTVERSION}:src \
		${MASTER_SITE_LOCAL}/gahr/:fluid \
		http://people.freebsd.org/~gahr/distfiles/:fluid \
		http://www.alsa-project.org/~james/sound-fonts/:fluid
DISTFILES=	${PORTNAME}-src-${DISTVERSION}${EXTRACT_SUFX}:src \
		8MBGMSFX.SF2:fluid
EXTRACT_ONLY=	${PORTNAME}-src-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Multitrack tablature editor and player

BUILD_DEPENDS=	${JAVALIBDIR}/swt-devel.jar:${PORTSDIR}/x11-toolkits/swt-devel \
		${JAVALIBDIR}/itext.jar:${PORTSDIR}/devel/itext \
		${JAVALIBDIR}/gervill.jar:${PORTSDIR}/audio/gervill
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	fluidsynth.1:${PORTSDIR}/audio/fluidsynth \
    		jack.0:${PORTSDIR}/audio/jack

MAKE_ENV+=	PREFIX=${PREFIX} INSTALL_DOC_DIR=${DOCSDIR} \
		INSTALL_SHARE_DIR=${DATADIR}

USES=		gmake pkgconfig
NO_STAGE=	yes
USE_JAVA=	yes
USE_ANT=	yes
USE_GECKO=	libxul
USE_LDCONFIG=	yes
JAVA_VERSION=	1.6+
NOCCACHE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}/TuxGuitar

.if !defined(WITHOUT_MAN)
MAN1=		tuxguitar.1
.endif

.include <bsd.port.pre.mk>
PLUGINS=	ascii browser-ftp compat converter fluidsynth gervill gtp \
		jsa lilypond midi musicxml oss pdf ptb tef tray tuner

SUB_FILES=	tuxguitar
SUB_LIST=	DATADIR=${DATADIR} \
		PREFIX=${PREFIX} \
		JAVALIBDIR=${JAVALIBDIR} \
		GECKO=${GECKO:S/19//}

post-extract:
	${CP} ${DISTDIR}/8MBGMSFX.SF2 ${WRKDIR}

post-patch:
	${FIND} ${WRKSRC}/.. -name build.properties | ${XARGS} ${REINPLACE_CMD} -e '\
	    s|path\.swt=.*|path.swt=${JAVAJARDIR}/swt-devel.jar|; \
	    s|path\.itext=.*|path.itext=${JAVAJARDIR}/itext.jar|; \
	    s|path\.gervill=.*|path.gervill=${JAVAJARDIR}/gervill.jar|'
	${FIND} ${WRKSRC}/.. -name GNUmakefile | ${XARGS} ${REINPLACE_CMD} -e '\
	    s|-I$$(shell gcj -print-file-name=include/)|-I${JAVA_HOME}/include \
	    -I${JAVA_HOME}/include/freebsd -I${LOCALBASE}/include|; \
	    s|LDFLAGS\?=.*|LDFLAGS?=-L${LOCALBASE}/lib|'
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g; \
	    s|%%PREFIX%%|${PREFIX}|g; \
	    s|%%JAVAJARDIR%%|${JAVAJARDIR}|g; \
	    s|%%JAVASHAREDIR%%|${JAVASHAREDIR}|g; \
	    s|%%DATADIR%%|${DATADIR}|g; \
	    s|%%DOCSDIR%%|${DOCSDIR}|g' \
	    ${WRKSRC}/build.properties

post-build:
.for p in ${PLUGINS}
	(cd ${WRKSRC}/../TuxGuitar-${p}; \
	    ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} ${ALL_TARGET})
.endfor
	cd ${WRKSRC}/../TuxGuitar-oss/jni && ${GMAKE}
	cd ${WRKSRC}/../TuxGuitar-fluidsynth/jni && ${GMAKE}
	cd ${WRKSRC}/../TuxGuitar-jack/jni && ${GMAKE}

do-install:
	${INSTALL} -d ${DATADIR}
	${INSTALL} -d ${DATADIR}/plugins
	# Main program and plugins
	${INSTALL_SCRIPT} ${WRKDIR}/tuxguitar ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tuxguitar.jar ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../misc/*.tg ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/8MBGMSFX.SF2 ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../TuxGuitar-oss/jni/libtuxguitar-oss-jni.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/../TuxGuitar-fluidsynth/jni/libtuxguitar-fluidsynth-jni.so ${PREFIX}/lib
.for p in ${PLUGINS}
	${INSTALL_DATA} ${WRKSRC}/../TuxGuitar-${p}/tuxguitar-${p}.jar ${DATADIR}/plugins
.endfor
	# Inline documentation
	cd ${WRKSRC}/share/help &&   ${COPYTREE_SHARE} \* ${DATADIR}/help
	cd ${WRKSRC}/share/lang &&   ${COPYTREE_SHARE} \* ${DATADIR}/lang
	cd ${WRKSRC}/share/scales && ${COPYTREE_SHARE} \* ${DATADIR}/scales
	cd ${WRKSRC}/share/skins &&  ${COPYTREE_SHARE} \* ${DATADIR}/skins

	# XPM icon
	${INSTALL} -d ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/../misc/tuxguitar.xpm ${PREFIX}/share/pixmaps

	# Desktop entry
	${INSTALL} -d ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/../misc/tuxguitar.desktop ${PREFIX}/share/applications

.if !defined(WITHOUT_MAN)
	# MAN page
	${INSTALL_MAN} ${WRKSRC}/../misc/tuxguitar.1 ${MANPREFIX}/man/man1
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif
	@${ECHO}
	@${ECHO} "SoundFonts for the FluidSynth plugin are available at:"
	@${ECHO} "${DATADIR}/8MBGMSFX.SF2"
	@${ECHO} "Add this path in the FluidSynth plugin configuration to"
	@${ECHO} "enable them."
	@${ECHO}

.include <bsd.port.post.mk>
