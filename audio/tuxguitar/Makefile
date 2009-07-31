# ex: ts=8
# New ports collection makefile for:   tuxguitar
# Date created:        26 April 2007
# Whom:                Pietro Cerutti (gahr@gahr.ch)
#
# $FreeBSD$
#

PORTNAME=	tuxguitar
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	audio java
MASTER_SITES=	SF:src \
		http://www.alsa-project.org/~james/sound-fonts/:fluid
DISTFILES=	${PORTNAME}-src-${DISTVERSION}${EXTRACT_SUFX}:src \
		8MBGMSFX.SF2:fluid
EXTRACT_ONLY=	${PORTNAME}-src-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Multitrack tablature editor and player

BUILD_DEPENDS=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt \
		${JAVALIBDIR}/itext.jar:${PORTSDIR}/devel/itext \
		${JAVALIBDIR}/gervill.jar:${PORTSDIR}/audio/gervill \
		ant:${PORTSDIR}/devel/apache-ant \
		gcj42:${PORTSDIR}/lang/gcc42-withgcjawt
RUN_DEPENDS=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt \
		${JAVALIBDIR}/itext.jar:${PORTSDIR}/devel/itext \
		${JAVALIBDIR}/gervill.jar:${PORTSDIR}/audio/gervill
LIB_DEPENDS=	fluidsynth.2:${PORTSDIR}/audio/fluidsynth

MAKE_ENV+=	PREFIX=${PREFIX} INSTALL_DOC_DIR=${DOCSDIR} \
		INSTALL_SHARE_DIR=${DATADIR}

USE_JAVA=	yes
USE_GECKO=	xulrunner firefox mozilla
USE_GMAKE=	yes
USE_LDCONFIG=	yes
JAVA_VERSION=	1.4+
JAVA_VENDOR=	bsdjava sun blackdown
NOCCACHE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}

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
		GECKO=${GECKO}

post-extract:
	${CP} ${DISTDIR}/8MBGMSFX.SF2 ${WRKDIR}

post-patch:
	${REINPLACE_CMD} -e 's|linux|freebsd|;s|JAVA_VERS|JAVA_PORT_VERSION|g; \
		/TuxGuitar-alsa/d; s|/usr/lib/jvm/java-6-sun/|${JAVA_HOME}|;' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g; \
		 s|%%JAVAJARDIR%%|${JAVAJARDIR}|g; \
		 s|%%PREFIX%%|${PREFIX}|g; \
		 s|%%DATADIR%%|${DATADIR}|g; \
		 s|%%DISTVERSION%%|${DISTVERSION}|g; \
		 s|%%DOCSDIR%%|${DOCSDIR}|g' \
		${WRKSRC}/TuxGuitar/build.properties
.for p in ${PLUGINS}
	${REINPLACE_CMD} -e \
	    's|$${path.swt}|${JAVALIBDIR}/swt.jar|; \
	     s|$${path.itext}|${JAVALIBDIR}/itext.jar|' \
		${WRKSRC}/TuxGuitar-${p}/build.xml
.endfor
	${REINPLACE_CMD} -e 's|$${lib.swt.jar}|${JAVALIBDIR}/swt.jar|g' \
		${WRKSRC}/TuxGuitar/build.xml
	${REINPLACE_CMD} -e 's|$${path.gervill}|${JAVALIBDIR}/gervill.jar|g' \
		${WRKSRC}/TuxGuitar-gervill/build.xml

	${REINPLACE_CMD} -e 's|CFLAGS?|CFLAGS+|g;\
	    s|gcj|${LOCALBASE}/bin/gcj42|;\
	    s|-I|-I${JAVA_HOME}/include -I${LOCALBASE}/include -I|;\
	    s|/usr/lib|${LOCALBASE}/lib|' \
	    ${WRKSRC}/TuxGuitar-oss/jni/GNUmakefile \
	    ${WRKSRC}/TuxGuitar-fluidsynth/jni/GNUmakefile

do-install:
	${INSTALL} -d ${DATADIR}
	${INSTALL} -d ${DATADIR}/plugins
	# Main program and plugins
	${INSTALL_SCRIPT} ${WRKDIR}/tuxguitar ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/TuxGuitar/tuxguitar.jar ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/misc/*.tg ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/8MBGMSFX.SF2 ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/TuxGuitar-oss/jni/libtuxguitar-oss-jni.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/TuxGuitar-fluidsynth/jni/libtuxguitar-fluidsynth-jni.so ${PREFIX}/lib
.for p in ${PLUGINS}
	${INSTALL_DATA} ${WRKSRC}/TuxGuitar-${p}/tuxguitar-${p}.jar ${DATADIR}/plugins
.endfor
	# Inline documentation
	cd ${WRKSRC}/TuxGuitar/share/help &&   ${COPYTREE_SHARE} \* ${DATADIR}/help
	cd ${WRKSRC}/TuxGuitar/share/lang &&   ${COPYTREE_SHARE} \* ${DATADIR}/lang
	cd ${WRKSRC}/TuxGuitar/share/scales && ${COPYTREE_SHARE} \* ${DATADIR}/scales
	cd ${WRKSRC}/TuxGuitar/share/skins &&  ${COPYTREE_SHARE} \* ${DATADIR}/skins

	# XPM icon
	${INSTALL} -d ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/misc/tuxguitar.xpm ${PREFIX}/share/pixmaps

	# Desktop entry
	${INSTALL} -d ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/misc/tuxguitar.desktop ${PREFIX}/share/applications

.if !defined(WITHOUT_MAN)
	# MAN page
	${INSTALL_MAN} ${WRKSRC}/misc/tuxguitar.1 ${MANPREFIX}/man/man1
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/TuxGuitar/doc && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif
	@${ECHO}
	@${ECHO} "SoundFonts for the FluidSynth plugin are available at:"
	@${ECHO} "${DATADIR}/8MBGMSFX.SF2"
	@${ECHO} "Add this path in the FluidSynth plugin configuration to"
	@${ECHO} "enable them."
	@${ECHO}

.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
