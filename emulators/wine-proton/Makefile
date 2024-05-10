PORTNAME=	wine-proton
DISTVERSION=	9.0-1
PORTREVISION=	0
CATEGORIES=	emulators

MAINTAINER=	iwtcex@gmail.com
COMMENT=	Wine with a bit of extra spice
WWW=		https://github.com/ValveSoftware/wine

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgnutls.so:security/gnutls \
		libvulkan.so:graphics/vulkan-loader

# amd_ags_x64.so
LIB_DEPENDS+=	libdrm.so:graphics/libdrm \
		libdrm_amdgpu.so:graphics/libdrm

# winewayland.so
LIB_DEPENDS+=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libxkbregistry.so:x11/libxkbcommon

USES=		autoreconf bison desktop-file-utils gl gmake gnome gstreamer llvm:${_LLVM_VERSION},build localbase perl5 pkgconfig python:build sdl shebangfix tar:xz xorg
USE_GCC=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ValveSoftware
GH_PROJECT=	wine
GH_TAGNAME=	a8514f9606ee3fdc3d912c988f651edc5d7d0d55

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
		--enable-archs=${ARCH:S|amd64|x86_64|} \
		--with-mingw CROSSCC="clang" CROSSCFLAGS="-isystem ${FILESDIR}/clang" \
		--libdir=${PREFIX}/${PORTNAME}/lib \
		--disable-kerberos \
		--disable-tests \
		--with-fontconfig \
		--with-freetype \
		--with-gnutls \
		--with-gstreamer \
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
		--without-osmesa \
		--without-pcap \
		--without-pcsclite \
		--without-sane \
		--without-udev \
		--without-unwind \
		--without-usb \
		--without-v4l2

CONFIGURE_ENV=	CPPBIN="false" CPPFLAGS="" FLEX="${LOCALBASE}/bin/flex" JXRLIB_CFLAGS="-I${LOCALBASE}/include/jxrlib"

CFLAGS+=	-D__NR_futex="-1" -Werror=implicit-function-declaration
CFLAGS_i386+=	-mpreferred-stack-boundary=4 -mstackrealign
PIE_UNSAFE=	yes

BINARY_ALIAS+=	clang=${LOCALBASE}/bin/clang${_LLVM_VERSION} \
		lld-link=${LOCALBASE}/bin/lld-link${_LLVM_VERSION}

OPTIONS_DEFINE=	PULSEAUDIO
OPTIONS_DEFAULT=PULSEAUDIO
OPTIONS_SUB=	yes

PULSEAUDIO_DESC=		Build winepulse.drv

PULSEAUDIO_BUILD_DEPENDS=	${LOCALBASE}/include/pulse/pulseaudio.h:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ON=	--with-pulse
PULSEAUDIO_CONFIGURE_OFF=	--without-pulse

.include <bsd.port.pre.mk>

.if ${LLVM_DEFAULT} == 11
_LLVM_VERSION=	15
.else
_LLVM_VERSION=	${LLVM_DEFAULT}
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	WINE32="@comment " WINE64="" WINEARCH="x86_64"
CONFIGURE_ARGS+=--enable-win64
.else
PLIST_SUB+=	WINE32="" WINE64="@comment " WINEARCH="i386"
.endif

post-patch:
	${REINPLACE_CMD} 's/CFLAGS="$$llvm_extra_cflags $$llvm_cflags"/CFLAGS="$$CROSSCFLAGS $$llvm_extra_cflags $$llvm_cflags"/g' ${WRKSRC}/configure.ac

pre-configure:
	cd ${WRKSRC} && ${PYTHON_CMD} dlls/winevulkan/make_vulkan --xml vk.xml
	cd ${WRKSRC} && ${PERL5} tools/make_specfiles

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} depend
	cd ${WRKSRC} && ${PERL5} tools/make_requests

post-install:
.if ${ARCH} == i386
	${MV} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wineserver ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wineserver32
	${MV} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine       ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine.bin
	-${ELFCTL} -e +noaslr                                 ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine.bin
	${INSTALL_SCRIPT} ${FILESDIR}/wine.sh                 ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine
.else
	${INSTALL_SCRIPT} ${FILESDIR}/pkg32.sh                ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/pkg32.sh
	${MV} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine64     ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine64.bin
	${INSTALL_SCRIPT} ${FILESDIR}/wine.sh                 ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine64
	${INSTALL_SCRIPT} ${FILESDIR}/wine-wow64.sh           ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine
.endif
	${RM} -r ${STAGEDIR}${PREFIX}/${PORTNAME}/include
	${RM} -r ${STAGEDIR}${PREFIX}/share/man
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README.md ANNOUNCE.md AUTHORS
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
