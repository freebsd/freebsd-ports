PORTNAME=	wine-proton
DISTVERSION=	8.0-3
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
		llvm${_LLVM_VERSION}>=0:devel/llvm${_LLVM_VERSION}

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgnutls.so:security/gnutls \
		libvulkan.so:graphics/vulkan-loader

USES=		autoreconf bison desktop-file-utils gl gmake gnome gstreamer localbase pkgconfig python:build sdl shebangfix tar:xz xorg
USE_GCC=	yes
PIE_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ValveSoftware
GH_PROJECT=	wine
GH_TAGNAME=	8a8ec5f86d8ab1e1d4c6bc88dda016b5e8cf479e

USE_GL=		gl
USE_GNOME=	glib20
USE_GSTREAMER=	gl mpeg2dec x264 # https://github.com/ValveSoftware/wine/commit/8cdd506d7e68c27cd564c317320bfc8d3a999eda
USE_SDL=	sdl2
USE_XORG=	x11 xext xcomposite xcursor xi xinerama xrandr xrender

SHEBANG_FILES=	tools/make_requests tools/winemaker/winemaker \
		tools/winedump/function_grep.pl

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/${PORTNAME}

CONFIGURE_ARGS=	--verbose \
		--libdir=${PREFIX}/${PORTNAME}/lib \
		--disable-kerberos \
		--disable-tests \
		--with-fontconfig \
		--with-freetype \
		--with-gnutls \
		--with-gstreamer \
		--with-opengl \
		--with-oss \
		--with-sdl \
		--with-vulkan \
		--with-x \
		--with-xinerama \
		--with-xinput2 \
		--with-xrandr \
		--with-xrender \
		--with-pcap \
		--with-pthread \
		--with-mingw CROSSCC="clang" CROSSCFLAGS="-isystem ${FILESDIR}/clang" \
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
		--without-pcsclite \
		--without-sane \
		--without-udev \
		--without-unwind \
		--without-usb \
		--without-v4l2

CONFIGURE_ENV=	CPPBIN="false" CPPFLAGS="" FLEX="${LOCALBASE}/bin/flex" JXRLIB_CFLAGS="-I${LOCALBASE}/include/jxrlib"

CFLAGS+=	-D__NR_futex="-1" -Werror=implicit-function-declaration

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

.if (${LLVM_DEFAULT} == 10 || ${LLVM_DEFAULT} == 11)
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

pre-configure:
	cd ${WRKSRC} && ${PYTHON_CMD} dlls/winevulkan/make_vulkan --xml vk.xml

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} depend
	cd ${WRKSRC} && tools/make_requests

post-install:
.if ${ARCH} == i386
	${MV} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wineserver ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wineserver32
	${MV} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine       ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine.bin
	-${ELFCTL} -e +noaslr                                 ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine.bin
	${INSTALL_SCRIPT} ${FILESDIR}/wine.sh                 ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine
.else
	${INSTALL_SCRIPT} ${FILESDIR}/pkg32.sh                ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/pkg32.sh
	${MV} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine64     ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine64.bin
	-${ELFCTL} -e +noaslr                                 ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine64.bin
	${INSTALL_SCRIPT} ${FILESDIR}/wine.sh                 ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine64
	${INSTALL_SCRIPT} ${FILESDIR}/wine-wow64.sh           ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine
.endif
	${RM} -r ${STAGEDIR}${PREFIX}/${PORTNAME}/include
	${RM} -r ${STAGEDIR}${MANPREFIX}/man
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README ANNOUNCE AUTHORS
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
