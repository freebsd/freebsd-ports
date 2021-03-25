# $FreeBSD$

PORTNAME=	juce
DISTVERSION=	6.0.8
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ application framework to develop desktop and mobile applications

LICENSE=	JUCE6
LICENSE_NAME=	JUCE 6 End User License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	ladspa>0:audio/ladspa
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfreetype.so:print/freetype2 \
		libsysinfo.so:devel/libsysinfo

USES=		cmake compiler:c++11-lang gl localbase:ldflags xorg
USE_GL=		gl
USE_XORG=	x11 xcomposite xcursor xext xinerama xorgproto xrandr

USE_GITHUB=	yes
GH_ACCOUNT=	yurivict # juce-framework
GH_PROJECT=	JUCE
GH_TAGNAME=	107cc92

CMAKE_ON=	JUCE_BUILD_EXTRAS # JUCE_BUILD_EXAMPLES

CXXFLAGS+=	-I${LOCALBASE}/include/freetype2
LDFLAGS+=	-pthread -lfreetype
LDFLAGS+=	-lGL # while building NetworkGraphicsDemo ld: error: undefined symbol: glXGetCurrentContext referenced by ld-temp.o
LDFLAGS+=	-lasound # while building AudioPerformanceTest ld: error: undefined symbol: snd_seq_system_info_sizeof
LDFLAGS+=	-lsysinfo # while building Projucer ld: error: undefined symbol: sysinfo

CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS} -lsysinfo -lexecinfo" # for the step 'Building juceaide' during configure phase: https://github.com/juce-framework/JUCE/issues/877

PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	# fix fonts.conf path
	@${REINPLACE_CMD} -e ' \
		s|"/etc/fonts/fonts.conf"|"${PREFIX}/etc/fonts/fonts.conf"| ; \
		s|"/usr/share/fonts/fonts.conf"|"${PREFIX}/share/fonts/fonts.conf"| \
		' ${WRKSRC}/modules/juce_graphics/native/juce_linux_Fonts.cpp
	# fix JUCE modules path (but it still complains about the path)
	@${REINPLACE_CMD} -e ' \
		s|"~/JUCE|"${PREFIX}/include/JUCE-${PORTVERSION}| \
		' ${WRKSRC}/extras/Projucer/Source/Settings/jucer_StoredSettings.cpp

post-install:
	# install extras which are essential apps that aren't installed by the project for some reason
.for exe in AudioPerformanceTest AudioPluginHost BinaryBuilder NetworkGraphicsDemo Projucer UnitTestRunner
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/extras/${exe}/${exe}_artefacts/Release/${exe} ${STAGEDIR}${PREFIX}/bin
.endfor
	# fix path and strip juceaide
	cd ${STAGEDIR}${PREFIX} && ${MV} bin/JUCE-${PORTVERSION}/juceaide bin/ && ${RMDIR} bin/JUCE-${PORTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/juceaide

.include <bsd.port.mk>
