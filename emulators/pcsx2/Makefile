PORTNAME=	pcsx2
PORTVERSION=	1.7.3465
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Free and open-source PlayStation 2 emulator
WWW=	https://pcsx2.net

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64

# Notes on dependencies (see cmake/SearchForStuff.cmake):
# - rapidyaml (and c4core) come from 3rdparty/ (0.4.0 is needed)
# - glad comes from 3rdparty/ (conflicts with libglvnd)
# - zstd comes from 3rdparty/ (not detected yet)
LIB_DEPENDS=	libpng.so:graphics/png \
		libpulse.so:audio/pulseaudio \
		libSoundTouch.so:audio/soundtouch \
		libharfbuzz.so:print/harfbuzz \
		libfmt.so:devel/libfmt \
		libzip.so:archivers/libzip \
		libpulse.so:audio/pulseaudio \
		libjack.so:audio/jack \
		libsndio.so:audio/sndio
#		libryml.so:devel/rapidyaml \
#		libglad.so:graphics/glad \
#		libzstd.so:archivers/zstd

USES=		cmake desktop-file-utils gl gnome pkgconfig sdl xorg

USE_GITHUB=	yes
GH_PROJECT=	pcsx2
GH_TAGNAME=	v${PORTVERSION}
.include "${.CURDIR}/Makefile.tuples"

USE_GL=		egl
USE_GNOME=	glib20 gtk30
USE_SDL=	sdl2
USE_XORG=	ice x11 xcb xext xpm xrandr
USE_WX=		3.0+

# See: cmake/BuildParameters.cmake
CMAKE_ARGS+=	\
		-DCMAKE_REQUIRED_INCLUDES:STRING=${LOCALBASE}/include/ \
		-DCMAKE_INSTALL_DOCDIR=${DOCSDIR} \
		-DPACKAGE_MODE:BOOL=ON \
		-DQT_BUILD:BOOL=OFF \
		-DUSE_VTUNE:BOOL=OFF \
		-DUSE_VULKAN:BOOL=OFF \
		-DENABLE_TESTS:BOOL=OFF \
		-DDISABLE_PCSX2_WRAPPER:BOOL=ON \
		-DDISABLE_SETCAP:BOOL=ON
DATADIR=	${PREFIX}/share/PCSX2

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CMAKE_ON=	-DNO_TRANSLATION:BOOL=OFF
NLS_CMAKE_OFF=	-DNO_TRANSLATION:BOOL=ON

# For maintainer (do not forget to clean up Makefile.tuples afterwards to
# remove useless submodules)
Makefile.tuples::
	@${RM} -f ${.CURDIR}/Makefile.tuples
	@${RM} -rf ${WRKDIR}/.maintainer.checkout
	@${MKDIR} ${WRKDIR}/.maintainer.checkout && \
		cd ${WRKDIR}/.maintainer.checkout && \
		git clone --recursive --branch=v${PORTVERSION} \
			https://github.com/${PORTNAME}/${PORTNAME} . && \
		${SH} ${FILESDIR}/gen_gh_tuple.sh >> ${.CURDIR}/Makefile.tuples

.include <bsd.port.mk>
