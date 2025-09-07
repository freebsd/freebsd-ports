PORTNAME=	wine
DISTVERSION=	10.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	https://dl.winehq.org/wine/source/10.0/

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Microsoft Windows compatibility environment
WWW=		https://www.winehq.org

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

# Only devel/llvm17 and later come with necessary include files - PR274542
USES=		bison cpe desktop-file-utils gmake \
		llvm:min=17,build,noexport localbase \
		pkgconfig sdl shebangfix tar:xz
USE_GCC=	yes
USE_SDL=	sdl2

CPE_VENDOR=	winehq

CONFLICTS_INSTALL=	wine-devel

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--verbose \
		--disable-kerberos \
		--disable-tests \
		--without-capi \
		--without-coreaudio \
		--without-dbus \
		--without-ffmpeg \
		--without-gettext --without-gettextpo \
		--without-gphoto \
		--without-gssapi \
		--without-inotify \
		--without-krb5 \
		--with-mingw CROSSCC="clang" \
		--without-netapi \
		--without-opencl \
		--without-osmesa \
		--without-pcap \
		--without-pcsclite \
		--with-pthread \
		--without-pulse \
		--without-sane \
		--with-sdl \
		--without-udev \
		--without-unwind \
		--without-usb
CONFIGURE_ENV=	CPPBIN="${CPP}" FLEX="${LOCALBASE}/bin/flex"
WINELIBDIR=	${PREFIX}/lib
.if !defined(USE_LDCONFIG32)
USE_LDCONFIG=	${WINELIBDIR} ${WINELIBDIR}/wine
.endif
SHEBANG_FILES=	tools/make_requests tools/winemaker/winemaker \
		tools/winedump/function_grep.pl

BINARY_ALIAS+=	clang=${LOCALBASE}/bin/clang${LLVM_VERSION} \
		lld-link=${LOCALBASE}/bin/lld-link${LLVM_VERSION}

SUB_FILES=	pkg-message

PIE_UNSAFE=	yes

PORTDATA=	wine.inf

OPTIONS_DEFINE=	CUPS DOCS DOSBOX GNUTLS V4L WAYLAND X11 GECKO MONO
OPTIONS_DEFAULT=ALSA GNUTLS X11
OPTIONS_RADIO=	AUDIO
OPTIONS_RADIO_AUDIO=	ALSA OSS
OPTIONS_SUB=	yes

DOSBOX_DESC=	Use DOSBox to run MS-DOS programs
GECKO_DESC=	Bundle Gecko MSI package for Wine
MONO_DESC=	Bundle Mono MSI package for Wine
WAYLAND_DESC=	Wayland Support

PORTSCOUT=	limit:^10\.0

ALSA_CONFIGURE_WITH=	alsa
ALSA_USES=		gnome gstreamer
ALSA_USE=		GNOME=glib20
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>0:audio/alsa-plugins

CUPS_CONFIGURE_WITH=	cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

DOSBOX_RUN_DEPENDS=	dosbox:emulators/dosbox

GECKO_RUN_DEPENDS=	wine-gecko>0:emulators/wine-gecko

GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

MONO_RUN_DEPENDS=	wine-mono>0:emulators/wine-mono

OSS_CONFIGURE_WITH=	oss
OSS_USES=		gnome gstreamer
OSS_USE=		GNOME=glib20

V4L_CONFIGURE_WITH=	v4l2
V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

WAYLAND_CONFIGURE_WITH=	wayland
WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon

X11_CONFIGURE_WITH=	x fontconfig freetype opengl xinerama xinput2 xrandr xrender
X11_USES=		gl xorg
X11_USE=		GL=glu XORG=x11,xext,xcomposite,xcursor,xi,xinerama,xrandr,xrender
X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libvulkan.so:graphics/vulkan-loader

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MALSA} || ${PORT_OPTIONS:MOSS}
CONFIGURE_ARGS+=	--with-gstreamer
PLIST_SUB+=		GSTREAMER=""
.else
CONFIGURE_ARGS+=	--without-gstreamer
PLIST_SUB+=		GSTREAMER="@comment "
.endif

.if ${ARCH} == amd64
# Wine is composed of three parts:
#  - wine (aka this port on FreeBSD/i386) is the 32-bit component
#       and runs 32-bit programs.
#  - wine64 (aka this part of this port on FreeBSD/amd64) is the
#       64-bit component and runs 64-bit programs.
#  - wow64 (aka this port built on FreeBSD/i386) is a part of the
#       64-bit component [wine64] that runs 32-bit programs on FreeBSD/amd64.

# --libdir is required since Wine defaults to "${PREFIX}/lib64" on amd64.
CONFIGURE_ARGS+=	--enable-win64 --libdir=${PREFIX}/lib
PLIST_SUB+=		WINE32="@comment " WINE64="" WINEARCH="x86_64"

# Wine assumes a WoW64 package is available, which is not the case on
# FreeBSD yet.
post-patch:
	${REINPLACE_CMD} '/Exec/s|wine|wine64|g' ${WRKSRC}/loader/wine.desktop
	${MV} ${WRKSRC}/loader/*.man.in ${WRKSRC}/tools/wine/

.else
EXTRA_PATCHES+=	files/extra-patch-tools-winebuild-res32
PLIST_SUB+=		WINE32="" WINE64="@comment " WINEARCH="i386"

post-patch:
	${MV} ${WRKSRC}/loader/*.man.in ${WRKSRC}/tools/wine/
.endif

pre-build:
	cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_CMD} depend

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/tools/wine/wine.man	${STAGEDIR}${PREFIX}/share/man/man1/wine.1
	${GZIP_CMD}					${STAGEDIR}${PREFIX}/share/man/man1/wine.1
.for m in de.UTF-8 fr.UTF-8 pl.UTF-8
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/${m}/man1
	${INSTALL_MAN} ${WRKSRC}/tools/wine/wine.${m}.man	${STAGEDIR}${PREFIX}/share/man/${m}/man1/wine.1
	${GZIP_CMD}						${STAGEDIR}${PREFIX}/share/man/${m}/man1/wine.1
.endfor
.if ${ARCH} == i386
	${MV} ${STAGEDIR}${PREFIX}/bin/wineserver	${STAGEDIR}${PREFIX}/bin/wineserver32
	${MV} ${STAGEDIR}${PREFIX}/bin/wine		${STAGEDIR}${PREFIX}/bin/wine.bin
	-${ELFCTL} -e +noaslr				${STAGEDIR}${PREFIX}/bin/wine.bin
	${INSTALL_SCRIPT} ${FILESDIR}/wine.sh		${STAGEDIR}${PREFIX}/bin/wine
.else
	${MV} ${STAGEDIR}${PREFIX}/bin/wine64		${STAGEDIR}${PREFIX}/bin/wine64.bin
	-${ELFCTL} -e +noaslr				${STAGEDIR}${PREFIX}/bin/wine64.bin
	${INSTALL_SCRIPT} ${FILESDIR}/wine.sh		${STAGEDIR}${PREFIX}/bin/wine64
	${INSTALL_SCRIPT} ${FILESDIR}/wine-wow64.sh	${STAGEDIR}${PREFIX}/bin/wine
	${INSTALL_SCRIPT} ${FILESDIR}/pkg32.sh		${STAGEDIR}${DATADIR}/pkg32.sh
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ANNOUNCE.md AUTHORS README.md
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/programs/winedbg/README ${STAGEDIR}${DOCSDIR}/README.winedbg
	${INSTALL_DATA} ${WRKSRC}/tools/winedump/README ${STAGEDIR}${DOCSDIR}/README.winedump

.include <bsd.port.post.mk>
