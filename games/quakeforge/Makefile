# New ports collection makefile for:	QuakeForge
# Date created:		4 January 2000
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	QuakeForge
PORTVERSION=	0.5.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:qf/} \
		ftp://ftp.idsoftware.com/idstuff/quakeworld/unix/:qw
MASTER_SITE_SUBDIR=	quake/:qf
DISTNAME=	quakeforge-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:qf ${PROGFILE}:qw
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.if !defined(NO_WAD)
MASTER_SITES+=	http://www.libsdl.org/projects/quake/data/:wad
DISTFILES+=	${WADFILE}:wad
.endif
.if !defined(NO_SKINS)
MASTER_SITES+=	ftp://ftp.idsoftware.com/idstuff/quakeworld/skins/:skins
DISTFILES+=	${SKINFILES:S/$/:skins/}
.endif

MAINTAINER=	q@galgenberg.net
COMMENT=	Cleaned up copy of the GPLd Quake 1 source code

WADFILE=	quakesw-1.0.6.tar.gz
PROGFILE=	qwsv-2.30-glibc-i386-unknown-linux2.0.tar.gz
SKINFILES=	skinbase.zip qw_skins.zip

USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
WANT_SDL=	yes

MAN1=	pak.1 qfcc.1 qflight.1 qfvis.1 wad.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=--with-global-cfg=${PREFIX}/etc/quakeforge.conf \
		--with-sharepath=${PREFIX}/share/quakeforge \
		--disable-optimize

BUILD_DEPENDS+=	bison:${PORTSDIR}/devel/bison

.if defined(WITH_OPTIMIZED_CFLAGS) && !defined(WITHOUT_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -funroll-loops -fomit-frame-pointer -fno-common \
		-fexpensive-optimizations -fstrict-aliasing
.if ${ARCH} != "alpha"
CFLAGS+=	-ffast-math
.endif
.endif

.if ${HAVE_SDL:Msdl}!=""
WITH_SDL=	yes
.endif

.if exists(${LOCALBASE}/lib/libvga.so.1)
WITH_SVGALIB=	yes
.endif

.if exists(${X11BASE}/lib/libxmms.so.4)
WITH_XMMS=	yes
.endif

.if exists(${LOCALBASE}/lib/libvorbis.so.3)
WITH_VORBIS=	yes
.endif

.if defined(WITHOUT_CLIENTS)
CONFIGURE_ARGS+=--without-clients
PLIST_SUB+=	CLIENT="@comment "
WITHOUT_XMMS=	yes
WITHOUT_SVGALIB=	yes
WITHOUT_SDL=	yes
WITHOUT_VORBIS=	yes
.else
PLIST_SUB+=	CLIENT=""
.endif

.if !defined(WITHOUT_SVGALIB) && defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--with-svga=${LOCALBASE}
PLIST_SUB+=	SVGA=""
.else
CONFIGURE_ARGS+=--without-svga
PLIST_SUB+=	SVGA="@comment "
.endif

.if !defined(WITHOUT_VORBIS) && defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-ogg=${LOCALBASE} --with-vorbis=${LOCALBASE}
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=--disable-vorbis --without-ogg --without-ogg-libraries \
		--without-ogg-includes	--disable-oggtest
PLIST_SUB+=	VORBIS="@comment "
.endif

.if !defined(WITHOUT_XMMS) && defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=--with-xmms-prefix=${X11BASE}
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=--disable-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

.if !defined(WITHOUT_SDL) && defined(WITH_SDL)
USE_SDL=	sdl
CONFIGURE_ARGS+=--with-sdl=${LOCALBASE}
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--disable-sdl --disable-sdltest
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_STATIC_PLUGINS)
PLIST_SUB+=	PLUGIN="@comment "
CONFIGURE_ARGS+=--with-static-plugins
.else
PLIST_SUB+=	PLUGIN=""
.endif

.if !defined(NO_WAD)
PLIST_SUB+=	WAD=""
.else
PLIST_SUB+=	WAD="@comment "
.endif

.if !defined(NO_SKINS)
PLIST_SUB+=	SKIN=""
BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.else
PLIST_SUB+=	SKIN="@comment "
.endif

pre-everything::
.if !defined(NO_WAD)
	@${ECHO_MSG} "Define NO_WAD to stop from using shareware version!"
.endif
.if !defined(NO_SKINS)
	@${ECHO_MSG} "Define NO_SKINS to stop from installing skins"
.endif
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define WITH_OPTIMIZED_CFLAGS to optimize for speed"
.endif
.if !defined(WITH_SVGALIB)
	@${ECHO_MSG} "Define WITH_SVGALIB to use svgalib"
.endif
.if !defined(WITH_VORBIS)
	@${ECHO_MSG} "Define WITH_VORBIS to use Ogg Vorbis"
.endif
.if !defined(WITH_XMMS)
	@${ECHO_MSG} "Define WITH_XMMS to use XMMS"
.endif
.if !defined(WITH_SDL)
	@${ECHO_MSG} "Define WITH_SDL to use SDL"
.endif
.if !defined(WITHOUT_CLIENTS)
	@${ECHO_MSG} "Define WITHOUT_CLIENTS to disable building of the clients"
.endif
.if !defined(WITH_STATIC_PLUGINS)
	@${ECHO_MSG} "Define WITH_STATIC_PLUGINS to disable building plugins as shared objects"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' ${WRKSRC}/configure

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.if !defined(NO_WAD)
	${MKDIR} ${PREFIX}/share/quakeforge/id1 && \
	${TAR} xzf ${DISTDIR}/${WADFILE} -C ${PREFIX}/share/quakeforge --no-same-owner id1/pak0.pak
.endif
	${TAR} xzf ${DISTDIR}/${PROGFILE} -C ${PREFIX}/share/quakeforge qw/
.if !defined(NO_SKINS)
.for file in ${SKINFILES}
	${UNZIP_CMD} -n ${DISTDIR}/${file} -d ${PREFIX}/share/quakeforge/qw/skins
.endfor
	@cd ${PREFIX}/share/quakeforge/qw/skins && LANG=C ./fixskins.sh *
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/config ${DOCSDIR}/data/docs ${DOCSDIR}/ideas
	cd ${WRKSRC}/doc && \
		${INSTALL_MAN} *.txt *.q1 *.q2 *.ico *.gif *.fig *.h CodingStyle ${DOCSDIR} && \
		${INSTALL_MAN} config/*.cfg ${DOCSDIR}/config && \
		${INSTALL_MAN} data/*.txt ${DOCSDIR}/data && \
		${INSTALL_MAN} data/docs/* ${DOCSDIR}/data/docs && \
		${INSTALL_MAN} ideas/*.txt ${DOCSDIR}/ideas
.endif

post-install:
	@${SED} -e 's#$${PREFIX}#${PREFIX}#g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
