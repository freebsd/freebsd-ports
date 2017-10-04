# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	openjfx8
DISTVERSION=	8u172-b00
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	java x11-toolkits devel
MASTER_SITES=	https://github.com/t6/openjfx/releases/download/release/ \
		http://hg.openjdk.java.net/openjfx/8u/rt/archive/${DISTVERSION}${EXTRACT_SUFX}?dummy=/
PKGNAMESUFFIX=	-devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	JavaFX SDK overlay for OpenJDK 8

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	apache-ant>0:devel/apache-ant \
		antlr3>0:devel/antlr3 \
		gradle>=4.0:devel/gradle \
		${JAVALIBDIR}/junit.jar:java/junit \
		swt-devel>0:x11-toolkits/swt-devel
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	swt-devel>0:x11-toolkits/swt-devel

USES=		gettext-runtime jpeg sqlite
USE_GL=		gl
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango
USE_JAVA=	yes
JAVA_VERSION=	1.8
USE_LDCONFIG=	yes
USE_XORG=	x11 xtst xxf86vm

OPTIONS_DEFINE=	MEDIA TEST WEBKIT
OPTIONS_DEFAULT=	MEDIA WEBKIT
OPTIONS_SUB=	yes

MEDIA_DESC=	Build media module

MEDIA_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libsndio.so:audio/sndio
MEDIA_USES=	gmake
MEDIA_VARS=	COMPILE_MEDIA=true

TEST_USES=	display:test
TEST_VARS=	AWT_TEST=true FULL_TEST=true

# Gradle calls CMake during the build
WEBKIT_BUILD_DEPENDS=	cmake:devel/cmake
WEBKIT_IMPLIES=	MEDIA
WEBKIT_LIB_DEPENDS=	libicui18n.so:devel/icu
WEBKIT_USES=	bison compiler:c++14-lang gmake gperf perl5 pkgconfig \
		python:2.7,build
WEBKIT_USE=	GNOME=libxslt,libxml2 \
		PERL5=build \
		RUBY=yes \
		XORG=xcomposite,xdamage,xfixes,xrender,xt
WEBKIT_VARS=	RUBY_NO_RUN_DEPENDS=yes COMPILE_WEBKIT=true

# Move Gradle's home below ${WRKDIR} instead of using ${HOME}/.gradle
GRADLE_ENV=	GRADLE_USER_HOME=${WRKDIR}/gradle-home \
		CC=${CC} CXX=${CXX}
GRADLE_RUN=	${SETENV} ${GRADLE_ENV} gradle --no-daemon

PLIST_SUB=	ARCH=${ARCH} \
		JAVA_HOME=${JAVA_HOME}
WRKSRC=		${WRKDIR}/rt-${DISTVERSION}

# NOTE: This port won't build if ${JAVA_HOME}/jre/lib/ext/jfxrt.jar
# already exists on your system.  This is not a problem in Poudriere
# or Synth but something to be aware of if you're trying to build this
# port in a non-pristine environment.

# The BSD Makefiles for GStreamer-lite and Jfxmedia are based on the
# Linux versions.  Prepare the tree, so that we only see the changes
# from Linux's Makefile in our own patches.
pre-patch:
	@${CP} -r ${WRKSRC}/modules/media/src/main/native/jfxmedia/projects/linux \
		${WRKSRC}/modules/media/src/main/native/jfxmedia/projects/bsd
	@${CP} -r ${WRKSRC}/modules/media/src/main/native/gstreamer/projects/linux \
		${WRKSRC}/modules/media/src/main/native/gstreamer/projects/bsd

post-patch:
	@${CP} ${FILESDIR}/bsd.gradle ${WRKSRC}/buildSrc
# Add a *BSD native audio sink to GStreamer-lite instead of using the
# bundled ALSA sink.  Currently we add an sndio sink, but this is an extension
# point for eventually adding an OSS backend (or others) as an option as well.
# If you add a new one make sure it registers itself as "bsdaudiosink" as defined
# in modules/media/src/main/native/jfxmedia/platform/gstreamer/GstPipelineFactory.cpp
	@${MKDIR} ${WRKSRC}/modules/media/src/main/native/gstreamer/gstreamer-lite/gst-plugins-base/ext/bsdaudio
	@${CP} ${FILESDIR}/gstsndio.c ${FILESDIR}/sndiosink.c ${FILESDIR}/sndiosink.h \
		${WRKSRC}/modules/media/src/main/native/gstreamer/gstreamer-lite/gst-plugins-base/ext/bsdaudio
	@cd ${WRKSRC}/modules/media/src/main/native/gstreamer/gstreamer-lite/gst-plugins-base/ext/bsdaudio && \
		${LN} -s gstsndio.c gstbsdaudio.c && \
		${LN} -s sndiosink.c bsdaudiosink.c
# Pull Java dependencies from LOCALBASE
	@${REINPLACE_CMD} 's@/usr/local@${LOCALBASE}@g' \
		${WRKSRC}/build.gradle ${WRKSRC}/buildSrc/build.gradle
# Remove the bundled libicu and libsqlite3.  We use the system's
# versions instead.
	@${RM} -r ${WRKSRC}/modules/web/src/main/native/Source/ThirdParty/icu \
		${WRKSRC}/modules/web/src/main/native/Source/ThirdParty/sqlite

do-configure:
	@${MKDIR} ${WRKDIR}/gradle-home
	@${ECHO_CMD} "NUM_COMPILE_THREADS = ${MAKE_JOBS_NUMBER}" > ${WRKSRC}/gradle.properties
.for prop in COMPILE_MEDIA COMPILE_WEBKIT AWT_TEST FULL_TEST
	@${ECHO_CMD} "${prop} = ${${prop}:Ufalse}" >> ${WRKSRC}/gradle.properties
.endfor

do-build:
	@cd ${WRKSRC} && ${GRADLE_RUN} zips

do-install:
	@${MKDIR} ${STAGEDIR}${JAVA_HOME}
	@${TAR} -C ${STAGEDIR}${JAVA_HOME} \
		-xf ${WRKSRC}/build/bundles/javafx-sdk-overlay.zip
	@${FIND} ${STAGEDIR}${JAVA_HOME}/jre -name '*.so' -exec ${STRIP_CMD} \{\} \;

do-test-TEST-on:
	@cd ${WRKSRC} && ${GRADLE_RUN} check test

.include <bsd.port.mk>
