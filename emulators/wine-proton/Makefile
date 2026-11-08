PORTNAME=	wine-proton
DISTVERSION=	11.0-2
PORTREVISION=	1
CATEGORIES=	emulators
PKGNAMESUFFIX=	${FLAVOR:N${FLAVORS:[1]}:C/.+/-${FLAVOR}/}

MAINTAINER=	monwarez@mailoo.org
COMMENT=	Wine with a bit of extra spice
WWW=		https://github.com/ValveSoftware/wine

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		${LOCALBASE}/ffmpeg4/include/libavformat/avformat.h:multimedia/ffmpeg4 \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgnutls.so:security/gnutls \
		libvulkan.so:graphics/vulkan-loader \
		libhwloc.so:devel/hwloc2

# amd_ags_x64.so
LIB_DEPENDS+=	libdrm.so:graphics/libdrm \
		libdrm_amdgpu.so:graphics/libdrm

# winewayland.so
LIB_DEPENDS+=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libxkbregistry.so:x11/libxkbcommon

# we are avoiding LIB_DEPENDS because find-lib.sh brings ffmpeg 6
RUN_DEPENDS=	ffmpeg4>=0:multimedia/ffmpeg4

FLAVORS=	default pulse
FLAVOR?=	default

USES=		autoreconf bison desktop-file-utils gl gmake gnome gstreamer \
		llvm:min=17,build,noexport localbase perl5 pkgconfig \
		python:build sdl shebangfix tar:xz xorg
USE_CSTD=	gnu11
USE_GCC=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ValveSoftware
GH_PROJECT=	wine
GH_TAGNAME=	proton-wine-${DISTVERSION}

USE_GL=		gl
USE_GNOME=	glib20
USE_GSTREAMER=	gl good mpeg2dec x264 # https://github.com/ValveSoftware/wine/commit/8cdd506d7e68c27cd564c317320bfc8d3a999eda
USE_PERL5=	build
USE_SDL=	sdl2
USE_XORG=	x11 xext xcomposite xcursor xi xinerama xrandr xrender

SHEBANG_FILES=	tools/make_requests tools/winemaker/winemaker \
		tools/winedump/function_grep.pl

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/${PORTNAME}

CONFIGURE_ARGS=	--verbose \
		--enable-archs=i386,x86_64 \
		--with-mingw CROSSCC="clang" \
		--libdir=${PREFIX}/${PORTNAME}/lib \
		--disable-kerberos \
		--disable-tests \
		--with-fontconfig \
		--with-freetype \
		--with-gnutls \
		--with-gstreamer \
		--with-hwloc \
		--with-opengl \
		--with-oss \
		--with-pthread \
		--with-sdl \
		--with-vulkan \
		--with-wayland \
		--with-x \
		--with-xinerama \
		--with-xinput2 \
		--with-xrandr \
		--with-xrender \
		--without-alsa \
		--without-capi \
		--without-coreaudio \
		--without-cups \
		--without-dbus \
		--without-gettext \
		--without-gettextpo \
		--without-gphoto \
		--without-gssapi \
		--without-inotify \
		--without-krb5 \
		--without-netapi \
		--without-opencl \
		--without-pcap \
		--without-pcsclite \
		--without-sane \
		--without-udev \
		--without-unwind \
		--without-usb \
		--without-v4l2

CONFIGURE_ENV=	CPPBIN="false" CPPFLAGS="" FLEX="${LOCALBASE}/bin/flex" \
		JXRLIB_CFLAGS="-I${LOCALBASE}/include/jxrlib" \
		PKG_CONFIG_PATH="${LOCALBASE}/ffmpeg4/libdata/pkgconfig"

CFLAGS+=	-D__NR_futex="-1" -Werror=implicit-function-declaration -Wno-int-conversion
CFLAGS_i386+=	-mpreferred-stack-boundary=4 -mstackrealign
PIE_UNSAFE=	yes

CONFLICTS_INSTALL=	${PORTNAME}*

BINARY_ALIAS+=	clang=${LOCALBASE}/bin/clang${LLVM_VERSION} \
		lld-link=${LOCALBASE}/bin/lld-link${LLVM_VERSION}

OPTIONS_DEFINE=		PULSEAUDIO
OPTIONS_DEFAULT=	${OPTIONS_DEFAULT_${FLAVOR}}
OPTIONS_DEFAULT_pulse=	PULSEAUDIO
OPTIONS_SUB=		yes

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulse

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--enable-win64
PLIST_SUB+=		WINEARCH="x86_64"
.endif

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		dlls/winevulkan/make_vulkan --xml vk.xml --video-xml video.xml
	cd ${WRKSRC} && ${PERL5} tools/make_specfiles

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} depend
	cd ${WRKSRC} && ${PERL5} tools/make_requests

post-install:
	${ELFCTL} -e +noaslr	${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine
	${RM} -r ${STAGEDIR}${PREFIX}/${PORTNAME}/include \
		 ${STAGEDIR}${PREFIX}/share/man
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${ANNOUNCE.md AUTHORS README.md:L:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
