# New ports collection makefile for:   	squeak
# Date created:        			12 October 2001
# Whom:                			roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=		squeak
PORTVERSION=		3.9
PORTREVISION=		2
CATEGORIES=		lang
##################################################
MASTER_SITES=		http://www.squeakvm.org/unix/release/ \
			http://ftp.squeak.org/${PORTVERSION}/ \
			http://ftp.squeak.org/${PORTVERSION}/unix-linux/ \
			ftp://st.cs.uiuc.edu/Smalltalk/Squeak/${PORTVERSION}/ \
			ftp://st.cs.uiuc.edu/Smalltalk/Squeak/${PORTVERSION}/unix-linux/ \
			ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/${PORTVERSION}/ \
			ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/${PORTVERSION}/unix-linux/ \
			http://www.squeakland.org/installers/:plugin \
			http://squeakland.jp/plugin/installers/:jpplugin \
			http://squeak.610t.org/patches/:ximpatch
DISTFILES=		Squeak-${VMVERSION}.src${EXTRACT_SUFX} \
			Squeak${IMAGEVERSION}-${PATCHNUMBER}.zip \
			SqueakV3.sources.gz \
			SqueakV39.sources.gz
EXTRACT_ONLY=		Squeak-${VMVERSION}.src${EXTRACT_SUFX}

##################################################
MAINTAINER=		mutoh@openedu.org
COMMENT=		Full Smalltalk 80 with portability to UNIX, Mac, and Windows

# Don't set USE_ZIP as this breaks EXTRACT_CMD.
BUILD_DEPENDS=		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=		audio:${PORTSDIR}/audio/nas \
			ffi:${PORTSDIR}/devel/libffi

##################################################
VMVERSION=		3.9-7
IMAGEVERSION=		3.9-final
PATCHNUMBER=		7067
IMAGEDIR=		Squeak${IMAGEVERSION}-${PATCHNUMBER}

##################################################
OPTIONS+=		MPG_MMX		"MMX support (MPG plugin)" off
OPTIONS+=		NPSQUEAK	"browser plugin support" on
OPTIONS+=		RFB		"remote frame buffer support" on
OPTIONS+=		X		"X Windows support" on
OPTIONS+=		XIM		"XIM support (Implies X)" off

.include <bsd.port.pre.mk>

##################################################
XIM_PATCH=		SqueakImmX11Plugin3a${EXTRACT_SUFX}
PLUGIN_IMAGE=		SqueakPlugin.zip
JAPANESE_PLUGIN_IMAGE=		SqueakPlugin2005J2.zip

##################################################
DIST_SUBDIR=		squeak
ONLY_FOR_ARCHS=		i386
MAN1=			inisqueak.1 squeak.1
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

# Plugin image must be writable, because of it copy to user's ~/.npsqueak/ and
# be updated.
SHAREMODE=		644

FILES_TO_GZIP=		${IMAGEDIR}/Squeak${IMAGEVERSION}-${PATCHNUMBER}.image \
			${IMAGEDIR}/Squeak${IMAGEVERSION}-${PATCHNUMBER}.changes

##################################################
# Configure and Build
WRKSRC=			${WRKDIR}/Squeak-${VMVERSION}
CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}
CONFIGURE_SCRIPT=	../platforms/unix/config/configure
CONFIGURE_ARGS+=	--libdir=${PREFIX}/share \
			--without-quartz \
			LDFLAGS="-L${LOCALBASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include"

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
DISTFILES+=		SqueakPlugin.zip:plugin
WITH_NPSQUEAK=		yes
PLIST_NPSQUEAK=
FILES_TO_GZIP+=		SqueakPlugin.image
RUN_DEPENDS+=		bash:${PORTSDIR}/shells/bash
.endif

.if defined(WITHOUT_X)
CONFIGURE_ARGS+=	--without-x
PLIST_X=		"@comment feature not wanted - "
.else
USE_XORG=		x11
USE_GL=			yes
CONFIGURE_ARGS+=	--with-x
PLIST_X=
.endif

.if defined(WITH_MPG_MMX)
CONFIGURE_ARGS+=	--enable-mpg-mmx
.endif

.if defined(WITH_XIM)
DISTFILES+=		${XIM_PATCH}:ximpatch \
			${JAPANESE_PLUGIN_IMAGE}:jpplugin
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

SUB_FILES=		pkg-message
SUB_LIST=		VMVERSION=${VMVERSION}

PLIST_SUB=		IMAGEVERSION=${IMAGEVERSION}\
			PATCHNUMBER=${PATCHNUMBER}\
			VMVERSION=${VMVERSION}\
			PLIST_NPSQUEAK=${PLIST_NPSQUEAK}\
			PLIST_X=${PLIST_X} \
			PLIST_XIM=${PLIST_XIM}

##################################################
post-patch:
	@${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/platforms/unix/npsqueak/npsqueakregister.in \
		${WRKSRC}/platforms/unix/npsqueak/npsqueakrun.in \
		${WRKSRC}/platforms/unix/npsqueak/Makefile
	@${REINPLACE_CMD} -e "s,echo aout,echo elf," ${WRKSRC}/platforms/unix/config/configure
.if defined(WITH_XIM)
	@cd ${WRKSRC} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${XIM_PATCH} ${EXTRACT_AFTER_ARGS}
# Skip first patch for plugins.ext because patch place has changed.
	@cd ${WRKSRC} && \
		${PATCH} -S + -p0 < ImmX11.patch
.endif
# Fix external plugins
	@${ECHO_MSG} "EXTERNAL_PLUGINS = B3DAcceleratorPlugin PseudoTTYPlugin UnixOSProcessPlugin XDisplayControlPlugin Squeak3D AioPlugin ${EXT_PLUGINS}" > ${WRKSRC}/platforms/unix/src/plugins.ext
# Fix utmp.h
.if ${OSVERSION} > 900007
	@${REINPLACE_CMD} -e 's,<utmp.h>,<utmpx.h>,g' \
		${WRKSRC}/platforms/unix/plugins/PseudoTTYPlugin/openpty.h
.endif

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
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} SqueakV39.sources.gz ${PREFIX}/share/squeak/)
	(cd ${PREFIX}/share/squeak && ${EXTRACT_CMD} -d SqueakV39.sources.gz)
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${UNZIP_CMD} -u Squeak${IMAGEVERSION}-${PATCHNUMBER}.zip -d ${WRKDIR} Squeak${IMAGEVERSION}-${PATCHNUMBER}/*)
.if defined(WITH_NPSQUEAK)
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${UNZIP_CMD} -u ${PLUGIN_IMAGE} -d ${WRKDIR})
.endif
.for file in ${FILES_TO_GZIP}
	(cd ${WRKDIR} && ${GZIP_CMD} ${file} && ${INSTALL_DATA} ${file}.gz ${PREFIX}/share/squeak/)
.endfor
	(cd ${WRKDIR} && ${INSTALL_DATA} ${IMAGEDIR}/SqueakV39.sources ${PREFIX}/share/squeak/${VMVERSION})
	${INSTALL_SCRIPT} ${WRKSRC}/build/inisqueak ${PREFIX}/bin/inisqueak
	${CHMOD} 755 ${PREFIX}/bin/inisqueak
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
