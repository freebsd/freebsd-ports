# Created by: Pietro Cerutti (gahr@gahr.ch)
# $FreeBSD$

PORTNAME=	tuxguitar
PORTVERSION=	1.2
PORTREVISION=	10
CATEGORIES=	audio java
MASTER_SITES=	SF/${PORTNAME}/TuxGuitar/TuxGuitar-${PORTVERSION}:src \
		LOCAL/gahr/:fluid \
		http://people.freebsd.org/~gahr/distfiles/:fluid \
		http://www.alsa-project.org/~james/sound-fonts/:fluid
DISTNAME=	${PORTNAME}-src-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		8MBGMSFX.SF2:fluid
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multitrack tablature editor and player

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	${JAVALIBDIR}/swt-devel.jar:x11-toolkits/swt-devel \
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
WITH_GECKO=	libxul
USE_LDCONFIG=	yes
JAVA_VERSION=	1.6+
NOCCACHE=	yes

WRKSRC_SUBDIR=	TuxGuitar

OPTIONS_DEFINE=	DOCS

PLUGINS=	ascii browser-ftp compat converter fluidsynth gervill gtp \
		jsa lilypond midi musicxml oss pdf ptb tef tray tuner

SUB_FILES=	pkg-message tuxguitar
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
	    s|-I $$(shell $$(GCJ) -print-file-name=include/)|-I${JAVA_HOME}/include \
	    -I${JAVA_HOME}/include/freebsd -I${LOCALBASE}/include|; \
	    s|LDFLAGS\?=.*|LDFLAGS+=-L${LOCALBASE}/lib|; \
	    s|CFLAGS\?=|CFLAGS+=|'
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
	cd ${WRKSRC}/../TuxGuitar-oss/jni && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}
	cd ${WRKSRC}/../TuxGuitar-fluidsynth/jni && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}
	cd ${WRKSRC}/../TuxGuitar-jack/jni && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

do-install:
	@${INSTALL} -d ${STAGEDIR}${DATADIR}
	@${INSTALL} -d ${STAGEDIR}${DATADIR}/plugins
	# Main program and plugins
	${INSTALL_SCRIPT} ${WRKDIR}/tuxguitar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tuxguitar.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../misc/*.tg ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/8MBGMSFX.SF2 ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/../TuxGuitar-oss/jni/libtuxguitar-oss-jni.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/../TuxGuitar-fluidsynth/jni/libtuxguitar-fluidsynth-jni.so ${STAGEDIR}${PREFIX}/lib
.for p in ${PLUGINS}
	${INSTALL_DATA} ${WRKSRC}/../TuxGuitar-${p}/tuxguitar-${p}.jar ${STAGEDIR}${DATADIR}/plugins
.endfor
	# Inline documentation
	cd ${WRKSRC}/share/help &&   ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/help
	cd ${WRKSRC}/share/lang &&   ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/lang
	cd ${WRKSRC}/share/scales && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/scales
	cd ${WRKSRC}/share/skins &&  ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/skins

	# XPM icon
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/../misc/tuxguitar.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

	# Desktop entry
	@${INSTALL} -d ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/../misc/tuxguitar.desktop ${STAGEDIR}${PREFIX}/share/applications

	# MAN page
	${INSTALL_MAN} ${WRKSRC}/../misc/tuxguitar.1 ${STAGEDIR}${PREFIX}/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
