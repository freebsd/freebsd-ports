# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	openjfx8
DISTVERSION=	8u202-b07
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	java x11-toolkits devel
MASTER_SITES=	https://github.com/t6/openjfx/releases/download/release/ \
		http://hg.openjdk.java.net/openjfx/8u/rt/archive/${DISTVERSION}${EXTRACT_SUFX}?dummy=/
PKGNAMESUFFIX=	-devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	JavaFX SDK overlay for OpenJDK 8

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	No longer maintained upstream
ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	apache-ant>0:devel/apache-ant \
		antlr3>0:devel/antlr3 \
		gradle4>=4.8:devel/gradle4 \
		${JAVALIBDIR}/junit.jar:java/junit
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-runtime gl gnome jpeg localbase:ldflags pkgconfig \
		sqlite xorg
USE_GL=		gl
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 gtk30 pango
USE_JAVA=	yes
JAVA_VERSION=	1.8
USE_LDCONFIG=	yes
USE_XORG=	x11 xtst xxf86vm

CFLAGS+=	-Wno-unused-command-line-argument

WRKSRC=		${WRKDIR}/rt-${DISTVERSION}

PLIST_SUB=	ARCH=${ARCH} \
		JAVA_HOME=${JAVA_HOME}

OPTIONS_DEFINE=	MEDIA SWT TEST WEBKIT
OPTIONS_DEFAULT=	MEDIA WEBKIT
OPTIONS_SUB=	yes

MEDIA_DESC=	Media module
SWT_DESC=	SWT support

MEDIA_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libsndio.so:audio/sndio
MEDIA_USES=	gmake
MEDIA_VARS=	COMPILE_MEDIA=true

SWT_BUILD_DEPENDS=	swt>0:x11-toolkits/swt
SWT_RUN_DEPENDS=	swt>0:x11-toolkits/swt
SWT_VARS=	COMPILE_SWT=true

TEST_USES=	display:test
TEST_VARS=	AWT_TEST=true FULL_TEST=true

# Gradle calls CMake during the build
WEBKIT_IMPLIES=	MEDIA
WEBKIT_BUILD_DEPENDS=	cmake:devel/cmake
WEBKIT_LIB_DEPENDS=	libicui18n.so:devel/icu
WEBKIT_USES=	bison compiler:c++14-lang gmake gperf perl5 python:2.7,build
WEBKIT_USE=	GNOME=libxslt,libxml2 \
		PERL5=build \
		RUBY=yes \
		XORG=xcomposite,xdamage,xfixes,xrender,xt
WEBKIT_VARS=	RUBY_NO_RUN_DEPENDS=yes COMPILE_WEBKIT=true

# Move Gradle's home below ${WRKDIR} instead of using ${HOME}/.gradle
_GRADLE_ENV=	CC=${WRKDIR}/bin/ccwrapper \
		CXX=${WRKDIR}/bin/cxxwrapper \
		GRADLE_USER_HOME=${WRKDIR}/gradle-home
_GRADLE_RUN=	${SETENV} ${_GRADLE_ENV} gradle4 --no-daemon

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
	@${MKDIR} ${WRKDIR}/bin
	@${PRINTF} '#!/bin/sh\nexec ${CC} ${CFLAGS} ${LDFLAGS} "$$@"\n' > ${WRKDIR}/bin/ccwrapper
	@${PRINTF} '#!/bin/sh\nexec ${CXX} ${CXXFLAGS} ${LDFLAGS} "$$@"\n' > ${WRKDIR}/bin/cxxwrapper
	@${CHMOD} +x ${WRKDIR}/bin/ccwrapper ${WRKDIR}/bin/cxxwrapper
	@${SED} -e 's@/linux@/freebsd@g' -e 's@-DLINUX@-DFREEBSD@g' -e 's@LINUX@BSD@g' \
		-e 's@linux_@bsd_@g' -e 's@"-static-libgcc", "-static-libstdc++",@@g' \
		-e 's@"gcc"@"${WRKDIR}/bin/ccwrapper"@g' -e 's@"g\+\+"@"${WRKDIR}/bin/cxxwrapper"@g' \
		${WRKSRC}/buildSrc/linux.gradle > ${WRKSRC}/buildSrc/bsd.gradle
# Add a *BSD native audio sink to GStreamer-lite instead of using the
# bundled ALSA sink.  Currently we add an sndio sink, but this is an extension
# point for eventually adding an OSS backend (or others) as an option as well.
# If you add a new one make sure it registers itself as "bsdaudiosink" as defined
# in modules/media/src/main/native/jfxmedia/platform/gstreamer/GstPipelineFactory.cpp
	@${MKDIR} ${WRKSRC}/modules/media/src/main/native/gstreamer/gstreamer-lite/gst-plugins-base/ext/bsdaudio
	@${CP} ${FILESDIR}/gstsndio.* ${FILESDIR}/sndiosink.* \
		${WRKSRC}/modules/media/src/main/native/gstreamer/gstreamer-lite/gst-plugins-base/ext/bsdaudio
	@cd ${WRKSRC}/modules/media/src/main/native/gstreamer/gstreamer-lite/gst-plugins-base/ext/bsdaudio && \
		${LN} -s gstsndio.c gstbsdaudio.c && \
		${LN} -s sndiosink.c bsdaudiosink.c
# Pull Java dependencies from LOCALBASE
	@${REINPLACE_CMD} 's@/usr/local@${LOCALBASE}@g' \
		${WRKSRC}/build.gradle ${WRKSRC}/buildSrc/build.gradle
# Remove bundled libraries.  We use the system's versions instead.
	@cd ${WRKSRC}/modules/web/src/main/native/Source/ThirdParty && \
		${RM} -r icu libxml libxslt sqlite
	@${RM} -r ${WRKSRC}/modules/web/src/main/native/Source/WTF/icu
	@cd ${WRKSRC}/modules/media/src/main/native/gstreamer/3rd_party && \
		${RM} -r glib libffi

post-patch-SWT-off:
	@${RM} -r ${WRKSRC}/modules/graphics/src/main/java/com/sun/glass/ui/swt

do-configure:
	@${MKDIR} ${WRKDIR}/gradle-home
	@${ECHO_CMD} "NUM_COMPILE_THREADS = ${MAKE_JOBS_NUMBER}" > ${WRKSRC}/gradle.properties
.for prop in COMPILE_MEDIA COMPILE_WEBKIT AWT_TEST FULL_TEST
	@${ECHO_CMD} "${prop} = ${${prop}:Ufalse}" >> ${WRKSRC}/gradle.properties
.endfor
	@${ECHO_CMD} "BSD.compileSWT = ${COMPILE_SWT:Ufalse};" >> ${WRKSRC}/buildSrc/bsd.gradle

do-build:
	@cd ${WRKSRC} && ${_GRADLE_RUN} zips

do-install:
	@${MKDIR} ${STAGEDIR}${JAVA_HOME}
	@${TAR} -C ${STAGEDIR}${JAVA_HOME} \
		-xf ${WRKSRC}/build/bundles/javafx-sdk-overlay.zip
	@${FIND} ${STAGEDIR}${JAVA_HOME}/jre -name '*.so' -exec ${STRIP_CMD} \{\} \;

do-test-TEST-on:
	@cd ${WRKSRC} && ${_GRADLE_RUN} check test

.include <bsd.port.mk>
