# Created by: Gerald Pfeifer <gerald@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wine
DISTVERSION=	1.7.30
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/Source \
		http://ibiblio.org/pub/linux/system/emulators/wine/
PKGNAMESUFFIX=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	gerald@FreeBSD.org
COMMENT?=	Microsoft Windows compatibility environment

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		prelink:${PORTSDIR}/sysutils/prelink
LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2

CONFLICTS_INSTALL=	i386-wine-[0-9]* i386-wine-devel-[0-9]* wine-[0-9]*

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--verbose --disable-tests \
		--without-alsa --without-capi --without-dbus \
		--without-gphoto --without-gsm --without-gstreamer \
		--without-opencl --with-oss --without-sane --without-tiff \
		--with-xcomposite --without-xinerama
CONFIGURE_ENV=	FLEX="${LOCALBASE}/bin/flex"
WINELIBDIR?=	${PREFIX}/lib
.if !defined(USE_LDCONFIG32)
USE_LDCONFIG=	${WINELIBDIR} ${WINELIBDIR}/wine
.endif
ONLY_FOR_ARCHS=	i386
USES=		bison compiler:c11 gmake shebangfix tar:bzip2
SHEBANG_FILES=	tools/winemaker tools/winedump/function_grep.pl

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	COMPHOLIO CUPS DOCS DOSBOX GNUTLS HAL LDAP LIBXSLT MPG123 OPENAL V4L WINEMAKER X11 GECKO MONO
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

COMPHOLIO_DESC=	Include the Compholio patchset, needed for Pipelight support
DOSBOX_DESC=	Use DOSBox to run MS-DOS programs
LIBXSLT_DESC=	Use libxslt (only used by msxml3.dll)
WINEMAKER_DESC=	Fully support winemaker (requires Perl)
GECKO_DESC=	Bundle Gecko MSI package for Wine
MONO_DESC=	Bundle Mono MSI package for Wine

# USES needs to be before bsd.port.pre.mk
CUPS_CONFIGURE_WITH=	cups
CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client

DOSBOX_RUN_DEPENDS=	dosbox:${PORTSDIR}/emulators/dosbox

GECKO_RUN_DEPENDS=	${DATADIR}/gecko/wine_gecko-2.24-x86.msi:${PORTSDIR}/emulators/wine-gecko-devel

GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls

HAL_CONFIGURE_WITH=	hal
HAL_LIB_DEPENDS=	libhal.so:${PORTSDIR}/sysutils/hal

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

LIBXSLT_CONFIGURE_WITH=	xslt
LIBXSLT_LIB_DEPENDS=	libxslt.so:${PORTSDIR}/textproc/libxslt

MONO_RUN_DEPENDS=	${DATADIR}/mono/wine-mono-4.5.2.msi:${PORTSDIR}/emulators/wine-mono-devel

MPG123_CONFIGURE_WITH=	mpg123
MPG123_LIB_DEPENDS=	libmpg123.so:${PORTSDIR}/audio/mpg123

OPENAL_CONFIGURE_WITH=	openal
OPENAL_USES=		openal

V4L_CONFIGURE_WITH=	v4l
V4L_LIB_DEPENDS=	libv4l1.so:${PORTSDIR}/multimedia/libv4l

WINEMAKER_RUN_DEPENDS=	p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML

X11_CONFIGURE_WITH=	x fontconfig glu opengl xinput2 xrandr freetype
X11_USE=		GL=glu XORG=xcomposite,xcursor,xi,xpm,xrandr,xrender
X11_LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
			libfreetype.so:${PORTSDIR}/print/freetype2 \
			libjpeg.so:${PORTSDIR}/graphics/jpeg \
			liblcms2.so:${PORTSDIR}/graphics/lcms2 \
			libpng15.so:${PORTSDIR}/graphics/png

PORTDATA=	l_intl.nls wine.inf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPHOLIO}
MASTER_SITES+=	https://github.com/compholio/wine-compholio-daily/archive/:cho
COMP_DIST=	v${DISTVERSION}.tar.gz
DISTFILES+=	${COMP_DIST}:cho
USE_AUTOTOOLS=	autoconf
BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash \
		git:${PORTSDIR}/devel/git

pre-configure:
	cd ${WRKSRC} && ${TAR} xf ${DISTDIR}/${COMP_DIST} --strip-components 1
	cd ${WRKSRC} && ${MAKE_CMD} -C ./patches DESTDIR=${WRKSRC} install
.endif

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} depend

post-install:
	@${MV} -f ${STAGEDIR}${WINELIBDIR}/libwine.so.1.0 \
	          ${STAGEDIR}${WINELIBDIR}/libwine.so.1
	@${LN} -sf libwine.so.1 ${STAGEDIR}/${WINELIBDIR}/libwine.so
.if ${PORT_OPTIONS:MDOCS}
	-@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README ANNOUNCE AUTHORS
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/programs/winedbg/README ${STAGEDIR}${DOCSDIR}/README.winedbg
	@${INSTALL_DATA} ${WRKSRC}/tools/winedump/README ${STAGEDIR}${DOCSDIR}/README.winedump
.endif
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
