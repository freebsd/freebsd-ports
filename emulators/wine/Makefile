# Created by: Gerald Pfeifer <gerald@FreeBSD.org>

PORTNAME=	wine
DISTVERSION=	6.0.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/Source \
		http://mirrors.ibiblio.org/wine/source/6.0/

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Microsoft Windows compatibility environment

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libFAudio.so:audio/faudio \
		libxml2.so:textproc/libxml2

USES=		bison cpe desktop-file-utils gmake localbase \
		pkgconfig sdl shebangfix tar:xz
USE_GCC=	yes
USE_SDL=	sdl2

CPE_VENDOR=	winehq

CONFLICTS_INSTALL=	wine-devel-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--verbose \
		--disable-kerberos \
		--disable-tests \
		--without-alsa \
		--without-capi \
		--without-coreaudio \
		--without-dbus \
		--without-gettext --without-gettextpo \
		--without-gphoto \
		--without-gsm \
		--without-gstreamer \
		--without-hal \
		--without-inotify \
		--without-krb5 \
		--without-mingw \
		--without-netapi \
		--without-opencl \
		--without-osmesa \
		--with-oss \
		--with-pcap \
		--with-pthread \
		--without-pulse \
		--without-quicktime \
		--without-sane \
		--with-sdl \
		--without-tiff \
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

SUB_FILES=	pkg-message

PORTDATA=	wine.inf

OPTIONS_DEFINE=	CUPS DOCS DOSBOX GNUTLS LDAP LIBXSLT MPG123 OPENAL V4L WINEMAKER X11 GECKO MONO
OPTIONS_DEFAULT=GNUTLS OPENAL X11
OPTIONS_SUB=	yes

DOSBOX_DESC=	Use DOSBox to run MS-DOS programs
LIBXSLT_DESC=	Use libxslt (only used by msxml3.dll)
WINEMAKER_DESC=	Fully support winemaker (requires Perl)
GECKO_DESC=	Bundle Gecko MSI package for Wine
MONO_DESC=	Bundle Mono MSI package for Wine

PORTSCOUT=	limit:^6\.0

CUPS_CONFIGURE_WITH=	cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

DOSBOX_RUN_DEPENDS=	dosbox:emulators/dosbox

GECKO_RUN_DEPENDS=	wine-gecko>0:emulators/wine-gecko

GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

LIBXSLT_CONFIGURE_WITH=	xslt
LIBXSLT_LIB_DEPENDS=	libxslt.so:textproc/libxslt

MONO_RUN_DEPENDS=	wine-mono>0:emulators/wine-mono

MPG123_CONFIGURE_WITH=	mpg123
MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123

OPENAL_CONFIGURE_WITH=	openal
OPENAL_USES=		openal

V4L_CONFIGURE_WITH=	v4l2
V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

WINEMAKER_RUN_DEPENDS=	p5-XML-LibXML>0:textproc/p5-XML-LibXML

X11_CONFIGURE_WITH=	x cms fontconfig freetype jpeg opengl png vkd3d xinerama xinput2 xrandr xrender
X11_USES=		gl jpeg xorg
X11_USE=		GL=glu XORG=x11,xext,xcomposite,xcursor,xi,xinerama,xrandr,xrender
X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			liblcms2.so:graphics/lcms2 \
			libpng.so:graphics/png \
			libvulkan.so:graphics/vulkan-loader \
			libvkd3d.so:graphics/vkd3d

.include <bsd.port.pre.mk>

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
PLIST_SUB+=		WINE32="@comment " WINE64=""

# Wine assumes a WoW64 package is available, which is not the case on
# FreeBSD yet.
post-patch:
	${REINPLACE_CMD} '/Exec/s|wine|wine64|g' ${WRKSRC}/loader/wine.desktop

.else
PLIST_SUB+=		WINE32="" WINE64="@comment "
.endif

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} depend

post-install:
.if ${ARCH} == i386
	${MV} ${STAGEDIR}${PREFIX}/bin/wineserver   ${STAGEDIR}${PREFIX}/bin/wineserver32
	${MV} ${STAGEDIR}${PREFIX}/bin/wine         ${STAGEDIR}${PREFIX}/bin/wine.bin
	${INSTALL_SCRIPT} ${FILESDIR}/wine.sh       ${STAGEDIR}${PREFIX}/bin/wine
.else
	${MV} ${STAGEDIR}${PREFIX}/bin/wine64       ${STAGEDIR}${PREFIX}/bin/wine64.bin
	${INSTALL_SCRIPT} ${FILESDIR}/wine.sh       ${STAGEDIR}${PREFIX}/bin/wine64
	${INSTALL_SCRIPT} ${FILESDIR}/wine-wow64.sh ${STAGEDIR}${PREFIX}/bin/wine
	${INSTALL_SCRIPT} ${FILESDIR}/pkg32.sh      ${STAGEDIR}${DATADIR}/pkg32.sh
.endif
	@${MV} -f ${STAGEDIR}${WINELIBDIR}/libwine.so.1.0 \
	          ${STAGEDIR}${WINELIBDIR}/libwine.so.1
	@${LN} -sf libwine.so.1 ${STAGEDIR}/${WINELIBDIR}/libwine.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README ANNOUNCE AUTHORS
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/programs/winedbg/README ${STAGEDIR}${DOCSDIR}/README.winedbg
	${INSTALL_DATA} ${WRKSRC}/tools/winedump/README ${STAGEDIR}${DOCSDIR}/README.winedump

.include <bsd.port.post.mk>
