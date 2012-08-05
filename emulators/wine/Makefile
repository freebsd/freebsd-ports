# New ports collection makefile for:    wine
# Date created:         Sa   9 Nov 1996 00:52:22 MET
# Whom:			se
#
# $FreeBSD$
#

PORTNAME=	wine
DISTVERSION=	1.4.1
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/Source \
		http://ibiblio.org/pub/linux/system/emulators/wine/

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Microsoft Windows compatibility environment

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		jpeg:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms \
		png15:${PORTSDIR}/graphics/png \
		xml2:${PORTSDIR}/textproc/libxml2

CONFLICTS_INSTALL=	wine-1.5.*

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--verbose --disable-tests \
		--without-alsa --without-capi --without-dbus \
		--with-fontconfig --with-glu \
		--without-gphoto --without-gsm --without-gstreamer \
		--with-opengl --without-mpg123 --without-opencl \
		--with-oss --without-sane --without-tiff \
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

OPTIONS_DEFINE=	CUPS DOSBOX GNUTLS HAL LDAP LIBXSLT OPENAL WINEMAKER

DOSBOX_DESC=	Use DOSBox to run MS-DOS programs
LIBXSLT_DESC=	Use libxslt (only used by msxml3.dll)
WINEMAKER_DESC=	Fully support winemaker (requires Perl)

PORTDATA=	fonts/ generic.ppd l_intl.nls wine.inf

PORTSCOUT=	limitw:1,even

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCUPS}
CONFIGURE_ARGS+=	--with-cups
LIB_DEPENDS+=	cups:${PORTSDIR}/print/cups-client
.else
CONFIGURE_ARGS+=	--without-cups
.endif

.if ${PORT_OPTIONS:MDOSBOX}
RUN_DEPENDS+=	dosbox:${PORTSDIR}/emulators/dosbox
.endif

.if ${PORT_OPTIONS:MGNU_TLS}
CONFIGURE_ARGS+=	--with-gnutls
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if ${PORT_OPTIONS:MHAL}
CONFIGURE_ARGS+=	--with-hal
LIB_DEPENDS+=	hal:${PORTSDIR}/sysutils/hal
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
LIB_DEPENDS+=	xslt:${PORTSDIR}/textproc/libxslt
.else
CONFIGURE_ARGS+=	--without-xslt
.endif

.if ${PORT_OPTIONS:MOPENAL}
CONFIGURE_ARGS+=	--with-openal
USE_OPENAL=		yes
PLIST_SUB+=		OPENAL=""
.else
CONFIGURE_ARGS+=	--without-openal
PLIST_SUB+=		OPENAL="@comment "
.endif

.if ${PORT_OPTIONS:MWINEMAKER}
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
