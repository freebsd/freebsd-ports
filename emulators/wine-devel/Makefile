PORTNAME=	wine
DISTVERSION=	11.14
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	https://dl.winehq.org/wine/source/11.x/
PKGNAMESUFFIX=	-devel${FLAVOR:N${FLAVORS:[1]}:C/.+/-${FLAVOR}/}

MAINTAINER=	monwarez@mailoo.org
COMMENT=	Microsoft Windows compatibility environment
WWW=		https://www.winehq.org

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libhwloc.so:devel/hwloc2

FLAVORS=	default allaudio
FLAVOR?=	default

# Only devel/llvm17 and later come with necessary include files - PR274542
USES=		autoreconf bison cpe desktop-file-utils gmake llvm:min=17,build,noexport \
		localbase pkgconfig sdl shebangfix tar:xz
CPE_VENDOR=	winehq
USE_GCC=	yes
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/wine
USE_SDL=	sdl2

SHEBANG_FILES=	tools/make_requests tools/winemaker/winemaker \
		tools/winedump/function_grep.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--verbose \
		--enable-archs=i386,x86_64 \
		--disable-kerberos \
		--disable-tests \
		--without-capi \
		--without-coreaudio \
		--without-dbus \
		--without-gettext --without-gettextpo \
		--without-gphoto \
		--without-gssapi \
		--with-hwloc \
		--without-inotify \
		--without-krb5 \
		--with-mingw CROSSCC="clang" \
		--without-netapi \
		--without-opencl \
		--without-pcap \
		--without-pcsclite \
		--with-pthread \
		--without-sane \
		--with-sdl \
		--without-udev \
		--without-unwind \
		--with-usb
CONFIGURE_ENV=	CPPBIN="${CPP}" FLEX="${LOCALBASE}/bin/flex"

PIE_UNSAFE=	yes

CONFLICTS_INSTALL=	wine

BINARY_ALIAS=	clang=${LOCALBASE}/bin/clang${LLVM_VERSION} \
		lld-link=${LOCALBASE}/bin/lld-link${LLVM_VERSION}

SUB_FILES=	pkg-message

PORTDATA=	wine.inf

# GECKO and MONO are intentionally kept at the end since they are just
# used to depends at runtime on wine-gecko-devel and wine-mono-devel
OPTIONS_DEFINE=		CUPS DOCS DOSBOX FFMPEG GNUTLS V4L WAYLAND X11 GECKO MONO
OPTIONS_DEFAULT=	ALSA FFMPEG GNUTLS OSS WAYLAND X11
.if ${FLAVOR} == allaudio
OPTIONS_DEFAULT+=	PULSEAUDIO
.endif
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA OSS PULSEAUDIO
OPTIONS_SUB=		yes

DOSBOX_DESC=	Use DOSBox to run MS-DOS programs
GECKO_DESC=	Bundle Gecko MSI package for Wine
MONO_DESC=	Bundle Mono MSI package for Wine
WAYLAND_DESC=	Wayland Support

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>0:audio/alsa-plugins
ALSA_USES=		gnome gstreamer
ALSA_USE=		GNOME=glib20
ALSA_CONFIGURE_WITH=	alsa

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CONFIGURE_WITH=	cups

DOSBOX_RUN_DEPENDS=	dosbox:emulators/dosbox

FFMPEG_LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_WITH=	ffmpeg

GECKO_RUN_DEPENDS=	wine-gecko-devel>0:emulators/wine-gecko-devel

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

MONO_RUN_DEPENDS=	wine-mono-devel>0:emulators/wine-mono-devel

OSS_USES=		gnome gstreamer
OSS_USE=		GNOME=glib20
OSS_CONFIGURE_WITH=	oss

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_USES=		gnome gstreamer
PULSEAUDIO_USE=			GNOME=glib20
PULSEAUDIO_CONFIGURE_WITH=	pulse

V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_WITH=	v4l2

WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_CONFIGURE_WITH=	wayland

X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libvulkan.so:graphics/vulkan-loader
X11_USES=		gl xorg
X11_USE=		GL=glu XORG=x11,xcomposite,xcursor,xext,xi,xinerama,xrandr,xrender
X11_CONFIGURE_WITH=	fontconfig freetype opengl x xinerama xinput2 xrandr xrender

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MALSA} || ${PORT_OPTIONS:MOSS} || ${PORT_OPTIONS:MPULSEAUDIO}
CONFIGURE_ARGS+=	--with-gstreamer
PLIST_SUB+=		GSTREAMER=""
.else
CONFIGURE_ARGS+=	--without-gstreamer
PLIST_SUB+=		GSTREAMER="@comment "
.endif

.if ${ARCH} == amd64
# --libdir is required since Wine defaults to "${PREFIX}/lib64" on amd64.
CONFIGURE_ARGS+=	--enable-win64 --libdir=${PREFIX}/lib
PLIST_SUB+=		WINEARCH="x86_64"
.endif

pre-build:
	cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_CMD} depend

post-install:
	${ELFCTL} -e +noaslr				${STAGEDIR}${PREFIX}/bin/wine

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ANNOUNCE.md AUTHORS README.md
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/programs/winedbg/README ${STAGEDIR}${DOCSDIR}/README.winedbg
	${INSTALL_DATA} ${WRKSRC}/tools/winedump/README ${STAGEDIR}${DOCSDIR}/README.winedump

.include <bsd.port.post.mk>
