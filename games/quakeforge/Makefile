# New ports collection makefile for:	QuakeForge
# Date created:		4 January 2000
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	QuakeForge
PORTVERSION=	0.5.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.idsoftware.com/idstuff/quakeworld/unix/
MASTER_SITE_SUBDIR=	quake
DISTNAME=	quakeforge-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PROGFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.if !defined(NO_WAD)
MASTER_SITES+=	http://www.devolution.com/~slouken/SDL/projects/quake/data/
DISTFILES+=	${WADFILE}
.endif
.if !defined(NO_SKINS)
MASTER_SITES+=	ftp://ftp.idsoftware.com/idstuff/quakeworld/skins/
DISTFILES+=	${SKINFILES}
.endif

MAINTAINER=	ports@FreeBSD.org

WADFILE=	quakesw-1.0.6.tar.gz
PROGFILE=	qwsv-2.30-glibc-i386-unknown-linux2.0.tar.gz
SKINFILES=	skinbase.zip qw_skins.zip

USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--with-global-cfg=${PREFIX}/etc/quakeforge.conf \
		--with-sharepath=${PREFIX}/share/quakeforge

CONFIGURE_TARGET=

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison

.if exists(${LOCALBASE}/lib/libSDL-1.1.so.5)
WITH_SDL=	yes
.endif

.if exists(${LOCALBASE}/lib/libvga.so.1)
WITH_SVGALIB=	yes
.endif

.if exists(${X11BASE}/lib/libxmms.so.3)
WITH_XMMS=	yes
.endif

.if exists(${LOCALBASE}/lib/libvorbis.so.2)
WITH_VORBIS=	yes
.endif

.if defined(WITHOUT_SERVERS)
CONFIGURE_ARGS+=--without-servers
PLIST_SUB+=	SERVER:="@comment "
.else
PLIST_SUB+=	SERVER:=""
.endif

.if defined(WITHOUT_TOOLS)
CONFIGURE_ARGS+=--without-tools
PLIST_SUB+=	TOOL:="@comment "
.else
PLIST_SUB+=	TOOL:=""
MAN1=	pak.1 qfcc.1 qflight.1 qfvis.1
.endif

.if defined(WITHOUT_CLIENTS)
CONFIGURE_ARGS+=--without-clients
PLIST_SUB+=	CLIENT:="@comment "
WITHOUT_XMMS=	yes
WITHOUT_SVGALIB=	yes
WITHOUT_SDL=	yes
WITHOUT_VORBIS=	yes
.else
PLIST_SUB+=	CLIENT:=""
.endif

.if !defined(WITHOUT_SVGALIB) && defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--with-svga=${LOCALBASE}
PLIST_SUB+=	SVGA:=""
.else
CONFIGURE_ARGS+=--without-svga
PLIST_SUB+=	SVGA:="@comment "
.endif

.if !defined(WITHOUT_VORBIS) && defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.2:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-ogg=${LOCALBASE} --with-vorbis=${LOCALBASE}
PLIST_SUB+=	VORBIS:=""
.else
CONFIGURE_ARGS+=--disable-vorbis --without-ogg --without-ogg-libraries \
		--without-ogg-includes	--disable-oggtest
PLIST_SUB+=	VORBIS:="@comment "
.endif

.if !defined(WITHOUT_XMMS) && defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.3:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=--with-xmms-prefix=${X11BASE}
PLIST_SUB+=	XMMS:=""
.else
CONFIGURE_ARGS+=--disable-xmms
PLIST_SUB+=	XMMS:="@comment "
.endif

.if !defined(WITHOUT_SDL) && defined(WITH_SDL)
LIB_DEPENDS+=	SDL-1.1.5:${PORTSDIR}/devel/sdl12
CONFIGURE_ARGS+=--with-sdl=${LOCALBASE}
CONFIGURE_ENV=	"SDL_CONFIG=${LOCALBASE}/bin/sdl11-config"
PLIST_SUB+=	SDL:=""
.else
CONFIGURE_ARGS+=--disable-sdl --disable-sdltest
PLIST_SUB+=	SDL:="@comment "
.endif

.if !defined(NO_WAD)
PLIST_SUB+=	WAD:=""
.else
PLIST_SUB+=	WAD:="@comment "
.endif

.if !defined(NO_SKINS)
PLIST_SUB+=	SKIN:=""
BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.else
PLIST_SUB+=	SKIN:="@comment "
.endif

pre-everything:
.if !defined(NO_WAD)
	@${ECHO_MSG} "Define NO_WAD to stop from using shareware version!"
.endif
.if !defined(NO_SKINS)
	@${ECHO_MSG} "Define NO_SKINS to stop from installing skins"
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
.if !defined(WITHOUT_TOOLS)
	@${ECHO_MSG} "Define WITHOUT_TOOLS to disable building of additional tools"
.endif
.if !defined(WITHOUT_SERVERS)
	@${ECHO_MSG} "Define WITHOUT_SERVERS to disable building of the servers"
.endif
.if !defined(WITHOUT_CLIENTS)
	@${ECHO_MSG} "Define WITHOUT_CLIENTS to disable building of the clients"
.endif

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.if !defined(NO_WAD)
	${MKDIR} ${PREFIX}/share/quakeforge/id1 && \
	${TAR} xzf ${DISTDIR}/${WADFILE} -C ${PREFIX}/share/quakeforge --no-same-owner id1/pak0.pak
.endif
.if !defined(WITHOUT_SERVERS)
	${TAR} xzf ${DISTDIR}/${PROGFILE} -C ${PREFIX}/share/quakeforge qw/
.endif
.if !defined(NO_SKINS)
.for file in ${SKINFILES}
	unzip -n ${DISTDIR}/${file} -d ${PREFIX}/share/quakeforge/qw/skins
.endfor
	@cd ${PREFIX}/share/quakeforge/qw/skins && ./fixskins.sh *
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/quakeforge/config
	${MKDIR} ${PREFIX}/share/doc/quakeforge/data/docs
	${MKDIR} ${PREFIX}/share/doc/quakeforge/ideas
	cd ${WRKSRC}/doc && \
		${INSTALL_MAN} *.txt *.q1 *.q2 *.ico *.gif *.fig *.h CodingStyle ${PREFIX}/share/doc/quakeforge && \
		${INSTALL_MAN} config/*.cfg ${PREFIX}/share/doc/quakeforge/config && \
		${INSTALL_MAN} data/*.txt ${PREFIX}/share/doc/quakeforge/data && \
		${INSTALL_MAN} data/docs/* ${PREFIX}/share/doc/quakeforge/data/docs && \
		${INSTALL_MAN} ideas/*.txt ${PREFIX}/share/doc/quakeforge/ideas
.endif

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's#$${PREFIX}#${PREFIX}#g'

.include <bsd.port.post.mk>
