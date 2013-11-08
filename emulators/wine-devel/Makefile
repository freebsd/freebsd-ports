# Created by: Gerald Pfeifer <gerald@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wine
DISTVERSION=	1.7.5
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/Source \
		http://ibiblio.org/pub/linux/system/emulators/wine/
PKGNAMESUFFIX=	-devel

MAINTAINER?=	gerald@FreeBSD.org
COMMENT?=	Microsoft Windows compatibility environment

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2

CONFLICTS_INSTALL=	i386-wine-* wine-1.4* wine-1.6*

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GCC=	any
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--verbose --disable-tests \
		--without-alsa --without-capi --without-dbus \
		--without-gphoto --without-gsm --without-gstreamer \
		--without-mpg123 --without-opencl \
		--with-oss --without-sane --without-tiff \
		--without-v4l --without-xcomposite --without-xinerama
CONFIGURE_ENV=	FLEX="${LOCALBASE}/bin/flex"
WINELIBDIR?=	${PREFIX}/lib
.if !defined(USE_LDCONFIG32)
USE_LDCONFIG=	${WINELIBDIR} ${WINELIBDIR}/wine
.endif
ONLY_FOR_ARCHS=	i386
USES=		bison gmake
USE_BZIP2=	yes

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	CUPS DOSBOX GNUTLS HAL LDAP LIBXSLT OPENAL WINEMAKER GECKO MONO X11
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

DOSBOX_DESC=	Use DOSBox to run MS-DOS programs
LIBXSLT_DESC=	Use libxslt (only used by msxml3.dll)
WINEMAKER_DESC=	Fully support winemaker (requires Perl)
GECKO_DESC=	Bundle Gecko MSI package for Wine
MONO_DESC=	Bundle Mono MSI package for Wine

PORTDATA=	l_intl.nls wine.inf

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCUPS}
CONFIGURE_ARGS+=	--with-cups
LIB_DEPENDS+=	libcups.so:${PORTSDIR}/print/cups-client
.else
CONFIGURE_ARGS+=	--without-cups
.endif

.if ${PORT_OPTIONS:MDOSBOX}
RUN_DEPENDS+=	dosbox:${PORTSDIR}/emulators/dosbox
.endif

.if ${PORT_OPTIONS:MGNUTLS}
CONFIGURE_ARGS+=	--with-gnutls
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if ${PORT_OPTIONS:MHAL}
CONFIGURE_ARGS+=	--with-hal
LIB_DEPENDS+=	libhal.so:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=	--without-hal
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=	--with-ldap
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${PORT_OPTIONS:MLIBXSLT}
CONFIGURE_ARGS+=	--with-xslt
LIB_DEPENDS+=	libxslt.so:${PORTSDIR}/textproc/libxslt
.else
CONFIGURE_ARGS+=	--without-xslt
.endif

.if ${PORT_OPTIONS:MOPENAL}
CONFIGURE_ARGS+=	--with-openal
USE_OPENAL=		yes
.else
CONFIGURE_ARGS+=	--without-openal
.endif

.if ${PORT_OPTIONS:MWINEMAKER}
RUN_DEPENDS+=	p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML
.endif

.if ${PORT_OPTIONS:MGECKO}
RUN_DEPENDS+=	${DATADIR}/gecko/wine_gecko-2.24-x86.msi:${PORTSDIR}/emulators/wine-gecko-devel
.endif

.if ${PORT_OPTIONS:MMONO}
RUN_DEPENDS+=	${DATADIR}/mono/wine-mono-0.0.8.msi:${PORTSDIR}/emulators/wine-mono
.endif

.if ${PORT_OPTIONS:MX11}
USE_GL=		glu
USE_XORG=	xcursor xi xpm xrandr xrender
LIB_DEPENDS+=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libpng15.so:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--with-fontconfig --with-glu --with-opengl \
		--with-xinput2 --with-xrandr --with-freetype
PORTDATA+=	fonts/
.else
CONFIGURE_ARGS+=--without-x --without-fontconfig --without-glu \
		--without-opengl --without-xinput2 --without-xrandr \
		--without-freetype
.endif

.if ${OSVERSION} < 800000
IGNORE=		lacks required sound support on FreeBSD before 8.0
.endif

pre-build:
	cd ${WRKSRC} && ${GMAKE} depend

post-install:
	@${MV} -f ${STAGEDIR}${WINELIBDIR}/libwine.so.1.0 \
	          ${STAGEDIR}${WINELIBDIR}/libwine.so.1
	@${LN} -sf libwine.so.1 ${STAGEDIR}/${WINELIBDIR}/libwine.so
.if !defined(NOPORTDOCS)
	-@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README ANNOUNCE AUTHORS
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/programs/winedbg/README ${STAGEDIR}${DOCSDIR}/README.winedbg
	@${INSTALL_DATA} ${WRKSRC}/tools/winedump/README ${STAGEDIR}${DOCSDIR}/README.winedump
.endif
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
