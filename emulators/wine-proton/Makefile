PORTNAME=	wine-proton
DISTVERSION=	6.3-2
PORTREVISION=	6
CATEGORIES=	emulators

MAINTAINER=	iwtcex@gmail.com
COMMENT=	Wine with a bit of extra spice

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libFAudio.so:audio/faudio \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgnutls.so:security/gnutls \
		libjpegxr.so:graphics/libjxr \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libvulkan.so:graphics/vulkan-loader \
		libxml2.so:textproc/libxml2

USES=		bison desktop-file-utils gettext-runtime gl gmake gnome gstreamer jpeg localbase openal pkgconfig sdl shebangfix tar:xz xorg
USE_GCC=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ValveSoftware
GH_PROJECT=	wine
GH_TAGNAME=	97f962cd469ee9b9b68d32e79849bf94cfe15581

USE_GL=		gl
USE_GNOME=	glib20
USE_GSTREAMER=	good
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
		--with-cms \
		--with-fontconfig \
		--with-freetype \
		--with-gnutls \
		--with-gstreamer \
		--with-jpeg \
		--with-jxrlib \
		--with-openal \
		--with-opengl \
		--with-oss \
		--with-png \
		--with-sdl \
		--with-vulkan \
		--with-x \
		--with-xinerama \
		--with-xinput2 \
		--with-xrandr \
		--with-xrender \
		--without-alsa \
		--without-capi \
		--without-cups \
		--without-dbus \
		--without-gettext \
		--without-gettextpo \
		--without-gphoto \
		--without-gsm \
		--without-inotify \
		--without-krb5 \
		--without-ldap \
		--without-mingw \
		--without-mpg123 \
		--without-opencl \
		--without-osmesa \
		--without-pulse \
		--without-sane \
		--without-tiff \
		--without-udev \
		--without-unwind \
		--without-usb \
		--without-v4l2 \
		--without-vkd3d \
		--without-xslt

CONFIGURE_ENV=	CPPBIN="${CPP}" FLEX="${LOCALBASE}/bin/flex" JXRLIB_CFLAGS="-I${LOCALBASE}/include/jxrlib"

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
PLIST_SUB+=	WINE32="@comment " WINE64=""
CONFIGURE_ARGS+=--enable-win64
.else
PLIST_SUB+=	WINE32="" WINE64="@comment "
.endif

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} depend

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
