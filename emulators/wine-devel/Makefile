# ex:ts=8
# New ports collection makefile for:    wine
# Date created:         Sa   9 Nov 1996 00:52:22 MET
# Whom:			se
#
# $FreeBSD$
#

PORTNAME=	wine
DISTVERSION=	1.3.31
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/Source \
		http://ibiblio.org/pub/linux/system/emulators/wine/

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Microsoft Windows compatibility layer for Unix-like systems

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms \
		png.6:${PORTSDIR}/graphics/png \
		xml2:${PORTSDIR}/textproc/libxml2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--verbose --disable-tests \
		--without-alsa --without-capi --with-glu \
		--without-gphoto --without-gsm --without-gstreamer \
		--with-opengl --without-mpg123 --with-oss --without-sane \
		--without-v4l --without-xcomposite --without-xinerama \
		--with-xinput2 --with-xrandr
CONFIGURE_ENV=	FLEX="${LOCALBASE}/bin/flex"
WINELIBDIR?=	${PREFIX}/lib
.if !defined(USE_LDCONFIG32)
USE_LDCONFIG=	${WINELIBDIR} ${WINELIBDIR}/wine
.endif
MAKE_JOBS_SAFE=	yes
MAN1=		msiexec.1 notepad.1 regedit.1 regsvr32.1 widl.1 wine.1 \
		wineboot.1 winebuild.1 winecfg.1 wineconsole.1 winedbg.1 \
		winedump.1 winefile.1 winegcc.1 winemaker.1 winemine.1 \
		winepath.1 wineserver.1 wmc.1 wrc.1
MLINKS=		winegcc.1 winecpp.1 \
		winegcc.1 wineg++.1
ONLY_FOR_ARCHS=	i386
USE_BISON=	build
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		glu
USE_XORG=	xcursor xi xpm xrandr xrender

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	CUPS	"Use CUPS (Common UNIX Printing System)"	Off \
		GNUTLS	"Use GnuTLS"					Off \
		HAL	"Use HAL (Hardware Abstraction Layer)"		Off \
		LDAP	"Use LDAP"					Off \
		LIBXSLT	"Use libxslt (only used by msxml3.dll)"		Off \
		OPENAL	"Use OpenAL (3D audio library)"			Off \
		WINEMAKER "Fully support winemaker (requires Perl)"	Off

PORTDATA=	fonts/ generic.ppd l_intl.nls wine.inf

.include <bsd.port.pre.mk>

.ifdef WITHOUT_CUPS
CONFIGURE_ARGS+=	--without-cups
.else
CONFIGURE_ARGS+=	--with-cups
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
.endif

.ifdef WITH_GNUTLS
CONFIGURE_ARGS+=	--with-gnutls
LIB_DEPENDS+=	gnutls.47:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.ifdef WITH_HAL
CONFIGURE_ARGS+=	--with-hal
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=	--without-hal
.endif

.ifdef WITH_LDAP
CONFIGURE_ARGS+=	--with-ldap
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.ifdef WITH_LIBXSLT
CONFIGURE_ARGS+=	--with-xslt
LIB_DEPENDS+=	xslt.2:${PORTSDIR}/textproc/libxslt
.else
CONFIGURE_ARGS+=	--without-xslt
.endif

.ifdef WITH_OPENAL
CONFIGURE_ARGS+=	--with-openal
USE_OPENAL=		yes
PLIST_SUB+=		OPENAL=""
.else
CONFIGURE_ARGS+=	--without-openal
PLIST_SUB+=		OPENAL="@comment "
.endif

.ifdef WITH_WINEMAKER
RUN_DEPENDS+=	p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML
.endif

.if ${OSVERSION} < 800000
IGNORE=		lacks required sound support on FreeBSD before 8.0
.endif

pre-build:
	cd ${WRKSRC} && ${GMAKE} depend

post-install:
	@${RM} -f ${MAN1PREFIX}/man/de.UTF-8/man1/wine.1 \
	          ${MAN1PREFIX}/man/de.UTF-8/man1/winemaker.1 \
	          ${MAN1PREFIX}/man/de.UTF-8/man1/wineserver.1 \
	          ${MAN1PREFIX}/man/fr.UTF-8/man1/wine.1 \
	          ${MAN1PREFIX}/man/fr.UTF-8/man1/winemaker.1 \
	          ${MAN1PREFIX}/man/fr.UTF-8/man1/wineserver.1 \
	          ${MAN1PREFIX}/man/pl.UTF-8/man1/wine.1
	@-${RMDIR} -p ${MAN1PREFIX}/man/de.UTF-8/man1 \
	              ${MAN1PREFIX}/man/fr.UTF-8/man1 \
	              ${MAN1PREFIX}/man/pl.UTF-8/man1
	${MV} -f ${WINELIBDIR}/libwine.so.1.0 ${WINELIBDIR}/libwine.so.1
	${LN} -sf libwine.so.1 ${WINELIBDIR}/libwine.so
.if !defined(NOPORTDOCS)
	-@${MKDIR} ${DOCSDIR}
.for i in README ANNOUNCE AUTHORS
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/programs/winedbg/README ${DOCSDIR}/README.winedbg
	@${INSTALL_DATA} ${WRKSRC}/tools/winedump/README ${DOCSDIR}/README.winedump
.endif
	@${MKDIR} ${DESKTOPDIR}
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
