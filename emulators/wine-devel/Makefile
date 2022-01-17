# Created by: Gerald Pfeifer <gerald@FreeBSD.org>

PORTNAME=	wine
DISTVERSION=	7.0-rc6
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/Source \
		http://mirrors.ibiblio.org/wine/source/6.x/
PKGNAMESUFFIX=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	damjan.jov@gmail.com
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

CONFLICTS_INSTALL=	wine

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
		--without-gssapi \
		--without-gstreamer \
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

SUB_FILES=	pkg-message

PORTDATA=	wine.inf

OPTIONS_DEFINE=	CUPS DOCS DOSBOX GNUTLS LDAP OPENAL STAGING V4L WINEMAKER X11 GECKO MONO
OPTIONS_DEFAULT=GNUTLS OPENAL X11
OPTIONS_SUB=	yes

DOSBOX_DESC=	Use DOSBox to run MS-DOS programs
STAGING_DESC=	Include Wine Staging patchset (experimental&unsupported)
WINEMAKER_DESC=	Fully support winemaker (requires Perl)
GECKO_DESC=	Bundle Gecko MSI package for Wine
MONO_DESC=	Bundle Mono MSI package for Wine

CUPS_CONFIGURE_WITH=	cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

DOSBOX_RUN_DEPENDS=	dosbox:emulators/dosbox

GECKO_RUN_DEPENDS=	wine-gecko-devel>0:emulators/wine-gecko-devel

GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

MONO_RUN_DEPENDS=	wine-mono-devel>0:emulators/wine-mono-devel

OPENAL_CONFIGURE_WITH=	openal
OPENAL_USES=		openal

STAGING_MASTER_SITES=	https://github.com/wine-staging/wine-staging/archive/:staging
STAGING_DIST=		v${DISTVERSION}.tar.gz
STAGING_DISTFILES=	${STAGING_DIST}:staging
STAGING_EXTRACT_DEPENDS=	bash:shells/bash \
				git:devel/git \
				autoconf>0:devel/autoconf \
				gawk:lang/gawk
STAGING_LIB_DEPENDS=	libtxc_dxtn.so:graphics/s2tc

V4L_CONFIGURE_WITH=	v4l2
V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

WINEMAKER_RUN_DEPENDS=	p5-XML-LibXML>0:textproc/p5-XML-LibXML

X11_CONFIGURE_WITH=	x fontconfig freetype opengl vkd3d xinerama xinput2 xrandr xrender
X11_USES=		gl xorg
X11_USE=		GL=glu XORG=x11,xext,xcomposite,xcursor,xi,xinerama,xrandr,xrender
X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
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
PLIST_SUB+=		WINE32="@comment " WINE64="" WINEARCH="x86_64"

# Wine assumes a WoW64 package is available, which is not the case on
# FreeBSD yet.
post-patch:
	${REINPLACE_CMD} '/Exec/s|wine|wine64|g' ${WRKSRC}/loader/wine.desktop

.else
PLIST_SUB+=		WINE32="" WINE64="@comment " WINEARCH="i386"
.endif

post-extract-STAGING-on: fix-shebang
	@${LN} -s ${WRKDIR}/${PORTNAME}-staging-${DISTVERSION}/patches ${WRKSRC}/patches

post-patch-STAGING-on:
	cd ${WRKSRC} && ${PATCH} -p0 < ${PATCHDIR}/extra-gitapply
	cd ${WRKSRC} && bash ./patches/patchinstall.sh --backend=patch DESTDIR=${WRKSRC} --all

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

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README ANNOUNCE AUTHORS
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/programs/winedbg/README ${STAGEDIR}${DOCSDIR}/README.winedbg
	${INSTALL_DATA} ${WRKSRC}/tools/winedump/README ${STAGEDIR}${DOCSDIR}/README.winedump

check-wine-devel-vs-staging:
	@${GREP} %%STAGING%% pkg-plist | while read f; do \
	  f=`echo $$f | ${SED} -e 's:%%STAGING%%::' -e "s:%%DATADIR%%:${DATADIR}:"`; \
	  if [ -f "$$STAGEDIR/$$PREFIX/$$f" ] || [ -f "$$STAGEDIR/$$f" ]; then \
	    ${PRINTF} "%s no longer contingent on %%STAGING%%?\n" "$$f"; \
	  fi \
	done

.include <bsd.port.post.mk>
