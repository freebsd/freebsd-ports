# New ports collection makefile for:   	squeak
# Date created:        			12 October 2001
# Whom:                			roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=		squeak
PORTVERSION=		3.6
PORTREVISION=		7
CATEGORIES=		lang
##################################################
MASTER_SITES=		ftp://st.cs.uiuc.edu/Smalltalk/Squeak/3.6/ \
			ftp://st.cs.uiuc.edu/Smalltalk/Squeak/3.6/unix-linux/ \
			ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/3.6/ \
			ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/3.6/unix-linux/ \
			http://www-sor.inria.fr/~piumarta/squeak/unix/release/ \
			http://www.squeakland.org/installers/ \
			http://www.squeakland.jp/plugin/installers/ \
			http://squeak.610t.org/patches/
DISTFILES=		Squeak-${VMVERSION}.src.tar.gz \
			Squeak${IMAGEVERSION}-${PATCHNUMBER}-basic.zip \
			Squeak${IMAGEVERSION}-${PATCHNUMBER}-full.zip \
			SqueakPlugin.zip \
			SqueakV3.sources.gz \
			${XIM_PATCH} \
			${JAPANESE_PLUGIN_IMAGE}
EXTRACT_ONLY=		Squeak-${VMVERSION}.src.tar.gz

##################################################
MAINTAINER=		mutoh@openedu.org
COMMENT=		Full Smalltalk 80 with portability to UNIX, Mac, and Windows

# Don't set USE_ZIP as this breaks EXTRACT_CMD.
BUILD_DEPENDS=		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=		audio.2:${PORTSDIR}/audio/nas

##################################################
VMVERSION=		3.6-3
IMAGEVERSION=		3.6
PATCHNUMBER=		5429

##################################################
OPTIONS+=		MPG_MMX		"MMX support (MPG plugin)" off
OPTIONS+=		NPSQUEAK	"browser plugin support" on
OPTIONS+=		RFB		"remote frame buffer support" on
OPTIONS+=		FFI		"libffi support" off
OPTIONS+=		X		"X Windows support" on
OPTIONS+=		XIM		"XIM support (Implies X)" off

.include <bsd.port.pre.mk>

##################################################
XIM_PATCH=		SqueakImmX11Plugin2c.tar.gz
PLUGIN_IMAGE=		SqueakPlugin.zip
JAPANESE_PLUGIN_IMAGE=		SqueakPlugin2005J.zip

##################################################
DIST_SUBDIR=		squeak
ONLY_FOR_ARCHS=		i386
MAN1=			inisqueak.1 squeak.1
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

# Plugin image must be writable, because of it copy to user's ~/.npsqueak/ and
# be updated.
SHAREMODE=		644

# shared Libaries are to be installed in:
LDCONFIG_DIRS=		${PREFIX}/share/squeak/${VMVERSION}

FILES_TO_GZIP=		Squeak${IMAGEVERSION}-${PATCHNUMBER}-basic.image \
			Squeak${IMAGEVERSION}-${PATCHNUMBER}-basic.changes \
			Squeak${IMAGEVERSION}-${PATCHNUMBER}-full.image \
			Squeak${IMAGEVERSION}-${PATCHNUMBER}-full.changes

##################################################
# Configure and Build
WRKSRC=			${WRKDIR}/Squeak-${VMVERSION}
CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}
CONFIGURE_SCRIPT=	../platforms/unix/config/configure
CONFIGURE_ARGS+=	--libdir=${PREFIX}/share \
			--without-quartz \
			LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

# don't pass "-s" to install to avoid trying to strip a shell script
CONFIGURE_ENV=

##################################################
# Knobs
.if defined(WITHOUT_RFB)
CONFIGURE_ARGS+=	--without-rfb
.endif

.if defined(WITHOUT_NPSQUEAK)
CONFIGURE_ARGS+=	--without-npsqueak
PLIST_NPSQUEAK=		"@comment feature not wanted - "
.else
WITH_NPSQUEAK=		yes
PLIST_NPSQUEAK=
.endif

.if defined(WITHOUT_X)
CONFIGURE_ARGS+=	--without-x
PLIST_X=		"@comment feature not wanted - "
.else
USE_XLIB=		yes
CONFIGURE_ARGS+=	--with-x
PLIST_X=
.endif

.if defined(WITH_MPG_MMX)
CONFIGURE_ARGS+=	--enable-mpg-mmx
.endif

.if defined(WITH_FFI)
LIB_DEPENDS+=		ffi.2:${PORTSDIR}/devel/libffi
PLIST_FFI=
EXT_PLUGINS+=		SqueakFFIPrims
.else
CONFIGURE_ARGS+=	--without-ffi
PLIST_FFI=		"@comment feature not wanted - "
.endif

.if defined(WITH_XIM)
PLIST_XIM=
WITH_X=			yes
USE_ICONV=		yes
PLUGIN_IMAGE=		${JAPANESE_PLUGIN_IMAGE}
EXT_PLUGINS+=		ImmX11Plugin
.else
PLIST_XIM=		"@comment feature not wanted - "
.endif

.ifdef (CC)
MAKE_ARGS+=		CC="${CC}"
.endif

.ifdef (CFLAGS)
MAKE_ARGS+=		CCFLAGS="${CFLAGS}"
.endif

PKGMESSAGE=		${WRKDIR}/pkg-message
PKGMESSAGE_SUB=		PREFIX=${PREFIX} \
			VMVERSION=${VMVERSION}

PLIST_SUB=		IMAGEVERSION=${IMAGEVERSION}\
			PATCHNUMBER=${PATCHNUMBER}\
			VMVERSION=${VMVERSION}\
			PLIST_NPSQUEAK=${PLIST_NPSQUEAK}\
			PLIST_X=${PLIST_X} \
			PLIST_FFI=${PLIST_FFI} \
			PLIST_XIM=${PLIST_XIM}

##################################################
post-patch:
	@${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%X11BASE%%,${X11BASE},g" \
		${WRKSRC}/platforms/unix/npsqueak/npsqueakregister.in \
		${WRKSRC}/platforms/unix/npsqueak/Makefile
.if defined(WITH_XIM)
	@cd ${WRKSRC} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${XIM_PATCH} ${EXTRACT_AFTER_ARGS}
	@cd ${WRKSRC} && \
		${PATCH} -p0 < ImmX11.patch
.endif
# Fix external plugins
	@${ECHO_MSG} "EXTERNAL_PLUGINS = B3DAcceleratorPlugin UnixOSProcessPlugin XDisplayControlPlugin ${EXT_PLUGINS}" > ${WRKSRC}/src/plugins.ext

##################################################
pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}

##################################################
post-configure:
	@${REINPLACE_CMD} -E \
		-e s'|^(prefix).*$$|\1=${PREFIX}|' \
		-e s'|^(docdir).*$$|\1=${DOCSDIR}|' \
		${CONFIGURE_WRKSRC}/Makefile

##################################################
post-install:
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} SqueakV3.sources.gz ${PREFIX}/share/squeak/)
	(cd ${PREFIX}/share/squeak && ${EXTRACT_CMD} -d SqueakV3.sources.gz)
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${UNZIP_CMD} -u Squeak${IMAGEVERSION}-${PATCHNUMBER}-basic.zip -d ${WRKDIR})
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${UNZIP_CMD} -u Squeak${IMAGEVERSION}-${PATCHNUMBER}-full.zip -d ${WRKDIR})
	(cd ${WRKDIR} && ${INSTALL_DATA} ReadMe.txt ${PREFIX}/share/squeak/)
.for file in ${FILES_TO_GZIP}
	(cd ${WRKDIR} && ${GZIP_CMD} ${file} && ${INSTALL_DATA} ${file}.gz ${PREFIX}/share/squeak/)
.endfor
.if defined(WITH_NPSQUEAK)
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${UNZIP_CMD} -u ${PLUGIN_IMAGE} -d ${WRKDIR})
	(cd ${WRKDIR} && ${INSTALL_DATA} SqueakPlugin.image ${PREFIX}/share/squeak/npsqueak.image)
.endif
	${SED}	-e 's|VERSION=3.5-5180|VERSION=${IMAGEVERSION}-${PATCHNUMBER}|' \
		-e 's|IMAGE=Squeak3.5-5180|IMAGE=Squeak${IMAGEVERSION}-${PATCHNUMBER}|' \
		-e 's|CHANGES=Squeak3.5-5180|CHANGES=Squeak${IMAGEVERSION}-${PATCHNUMBER}|' \
		${WRKSRC}/build/inisqueak > ${WRKSRC}/build/inisqueak.tmp
	${INSTALL_SCRIPT} ${WRKSRC}/build/inisqueak.tmp ${PREFIX}/bin/inisqueak
	${CHMOD} 755 ${PREFIX}/bin/inisqueak
	@${SED} ${PKGMESSAGE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
