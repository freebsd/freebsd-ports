# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	openjfx8
PORTVERSION=	20170722
PORTREVISION=	1
CATEGORIES=	java x11-toolkits devel
MASTER_SITES=	https://bitbucket.org/tobik/openjfx-rt/get/freebsd${PORTVERSION}${EXTRACT_SUFX}?dummy=/
PKGNAMESUFFIX=	-devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	JavaFX (OpenJFX) SDK overlay for OpenJDK 8

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
USE_LDCONFIG=	yes
USE_XORG=	x11 xtst xxf86vm
JAVA_VERSION=	1.8

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
WEBKIT_USES=	bison compiler:c++11-lib gmake gperf perl5 pkgconfig \
		python:2.7,build
WEBKIT_USE=	GNOME=libxslt,libxml2 \
		PERL5=build \
		RUBY=yes \
		XORG=xcomposite,xdamage,xfixes,xrender,xt
WEBKIT_VARS=	RUBY_NO_RUN_DEPENDS=yes COMPILE_WEBKIT=true

PLIST_SUB=	ARCH=${ARCH} \
		JAVA_HOME=${JAVA_HOME}

WRKSRC=	${WRKDIR}/tobik-openjfx-rt-9ccdaef460fa

GRADLE_ENV=	GRADLE_USER_HOME=${WRKDIR}/gradle-home
GRADLE_RUN=	${SETENV} ${GRADLE_ENV} gradle --no-daemon

# NOTE: This port won't build if ${JAVA_HOME}/jre/lib/ext/jfxrt.jar
# already exists on your system.  This is not a problem in Poudriere
# or Synth but something to be aware of if you're trying to build this
# port in a non-pristine environment.

post-patch:
	@${REINPLACE_CMD} -E -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build.gradle ${WRKSRC}/buildSrc/build.gradle
# Remove the bundled libicu and libsqlite3.  We use the system's
# versions instead.
	@${RM} -r ${WRKSRC}/modules/web/src/main/native/Source/ThirdParty/icu \
		${WRKSRC}/modules/web/src/main/native/Source/ThirdParty/sqlite

do-configure:
# Gradle creates ${HOME}/.gradle, pretend home is somewhere else
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
