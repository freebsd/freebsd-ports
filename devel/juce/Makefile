PORTNAME=	juce
DISTVERSION=	8.0.6
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ application framework to develop desktop and mobile applications
WWW=		https://juce.com/ \
		https://github.com/juce-framework/JUCE

LICENSE=	JUCE6
LICENSE_NAME=	JUCE 6 End User License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

BROKEN_armv7=	compilation fails due to the 'mb' variable conflict, pending https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=283492
BROKEN_riscv64=	Hard-float 'd' ABI can't be used for a target that doesn't support the D instruction set extension (ignoring target-abi)

BUILD_DEPENDS=	ladspa>0:audio/ladspa
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libcurl.so:ftp/curl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjavascriptcoregtk-4.0.so:www/webkit2-gtk@40 \
		libpng16.so:graphics/png \
		libsoup-2.4.so:devel/libsoup \
		libsysinfo.so:devel/libsysinfo

USES=		cmake compiler:c++17-lang dos2unix gl gnome localbase:ldflags pkgconfig xorg
DOS2UNIX_FILES=	modules/juce_core/juce_core.h \
		modules/juce_dsp/containers/juce_AudioBlock_test.cpp
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 pango
USE_GL=		gl
USE_XORG=	x11 xcomposite xcursor xext xinerama xorgproto xrandr

USE_GITHUB=	yes
GH_ACCOUNT=	juce-framework
GH_PROJECT=	JUCE

CMAKE_ON=	JUCE_BUILD_EXTRAS
#CMAKE_ON+=	JUCE_BUILD_EXAMPLES

CXXFLAGS+=	-I${LOCALBASE}/include/freetype2 -DJUCE_INCLUDE_PNGLIB_CODE=0
LDFLAGS+=	-pthread -lfreetype -lpng16
LDFLAGS+=	-lGL # while building NetworkGraphicsDemo ld: error: undefined symbol: glXGetCurrentContext referenced by ld-temp.o
LDFLAGS+=	-lasound # while building AudioPerformanceTest ld: error: undefined symbol: snd_seq_system_info_sizeof
LDFLAGS+=	-lsysinfo # while building Projucer ld: error: undefined symbol: sysinfo

CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS} -lexecinfo" # for the step 'Building juceaide' during configure phase: https://github.com/juce-framework/JUCE/issues/877

PLIST_SUB+=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=		DEMOS

DEMOS_DESC=		Build and install demo programs
DEMOS_USES=		gnome pkgconfig
DEMOS_CMAKE_BOOL=	JUCE_BUILD_EXAMPLES
DEMOS_LDFLAGS=		-lexecinfo
DEMOS_USE=		GNOME=atk,cairo,gdkpixbuf,gtk30,pango
DEMOS_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libwebkit2gtk-4.0.so:www/webkit2-gtk@40 \
			libsoup-2.4.so:devel/libsoup
DEMO_FILES=	\
	AnalyticsCollectionDemo AnimationAppDemo AnimationDemo AudioAppDemo AudioLatencyDemo AudioPlaybackDemo AudioPluginDemo AudioRecordingDemo AudioSettingsDemo AudioSynthesiserDemo \
	BlocksDrawingDemo BlocksMonitorDemo BlocksSynthDemo BouncingBallWavetableDemo Box2DDemo ChildProcessDemo CodeEditorDemo ComponentDemo ComponentTransformsDemo ConvolutionDemo \
	CryptographyDemo DSPModulePluginDemo DialogsDemo FIRFilterDemo FlexBoxDemo FontsDemo GainDemo GraphicsDemo GridDemo HelloWorldDemo \
	IIRFilterDemo ImagesDemo InAppPurchasesDemo JavaScriptDemo KeyMappingsDemo LiveConstantDemo LookAndFeelDemo MDIDemo MPEDemo MenusDemo \
	MidiDemo MultiTouchDemo MultithreadingDemo NetworkingDemo OSCDemo OpenGLAppDemo OpenGLDemo OscillatorDemo OverdriveDemo PluckedStringsDemo \
	PropertiesDemo SIMDRegisterDemo SimpleFFTDemo StateVariableFilterDemo SystemInfoDemo TimersAndEventsDemo UnitTestsDemo ValueTreesDemo WaveShaperTanhDemo WebBrowserDemo \
	WidgetsDemo WindowsDemo XMLandJSONDemo
DEMOS_PLIST_FILES=	${DEMO_FILES:S/^/bin\/${PORTNAME}-/}
DEMOS_BROKEN=		build fails with JUCE_BUILD_EXAMPLES=ON, see https://github.com/juce-framework/JUCE/issues/1410

post-patch:
	# fix fonts.conf path
	@${REINPLACE_CMD} -i '' -e ' \
		s|"/etc/fonts/fonts.conf"|"${PREFIX}/etc/fonts/fonts.conf"| ; \
		s|"/usr/share/fonts/fonts.conf"|"${PREFIX}/share/fonts/fonts.conf"| \
		' ${WRKSRC}/modules/juce_graphics/native/juce_Fonts_linux.cpp
	# fix JUCE modules path (but it still complains about the path)
	@${REINPLACE_CMD} -i '' -e ' \
		s|"~/JUCE|"${PREFIX}/include/JUCE-${PORTVERSION}| \
		' ${WRKSRC}/extras/Projucer/Source/Settings/jucer_StoredSettings.cpp

post-install:
	# install extras which are essential apps that aren't installed by the project for some reason
.for exe in AudioPerformanceTest AudioPluginHost BinaryBuilder NetworkGraphicsDemo Projucer UnitTestRunner
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/extras/${exe}/${exe}_artefacts/Release/${exe} ${STAGEDIR}${PREFIX}/bin
.endfor
	# strip juceaide
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/JUCE-${PORTVERSION}/juceaide
	# workaround for https://github.com/juce-framework/JUCE/issues/1502
	@${REINPLACE_CMD} -e 's|.*VST3_HELPER\.cmake.*||' ${STAGEDIR}${PREFIX}/lib/cmake/JUCE-8.0.6/JUCEConfig.cmake

do-install-DEMOS-on:
.for e in ${DEMO_FILES}
	${INSTALL_PROGRAM} `${FIND} ${BUILD_WRKSRC} -name ${e}` ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${e}
.endfor

.include <bsd.port.mk>
