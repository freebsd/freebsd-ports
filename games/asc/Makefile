# New ports collection makefile for:	asc
# Date created:				16 February 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asc
PORTVERSION=	2.4.0.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}-hq/ASC%20Source/${PORTVERSION:R} \
		http://www.asc-hq.org/music/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ASC_MUSICS}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A turn based, multiplayer strategic game with very nice graphics

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/lib/libloki.so:${PORTSDIR}/devel/loki
LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		boost_regex.4:${PORTSDIR}/devel/boost-libs \
		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		expat.6:${PORTSDIR}/textproc/expat2
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS=	MUSIC "Install extra music files" off \
		XVID "Enable Xvid support" off

USE_BZIP2=	yes
USE_SDL=	image mixer sound sdl
USE_WX=		2.4+
WX_CONF_ARGS=	absolute
USE_LUA=	5.1
LUA_COMPS=	lua
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		asc.6 asc_demount.6 asc_mapedit.6 asc_mount.6 \
		asc_weaponguide.6
PLIST_FILES=	bin/asc bin/asc_demount bin/asc_mapedit bin/asc_mount \
		bin/asc_weaponguide \
		%%DATADIR%%/asc2_dlg.zip %%DATADIR%%/main.ascdat
PLIST_DIRS=	${ASC_MUSICDIR} %%DATADIR%%

CFLAGS+=	-D_UNICODE_BROKEN_
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_MUSIC)
ASC_MUSICS=	frontiers.ogg time_to_strike.ogg machine_wars.ogg
ASC_MUSICDIR=	%%DATADIR%%/music
.for file in ${ASC_MUSICS}
PLIST_FILES+=	${ASC_MUSICDIR}/${file}
.endfor
.else
.undef ASC_MUSICS
.undef ASC_MUSICDIR
.endif

.if defined(WITH_XVID)
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid
.else
CONFIGURE_ENV+=	ac_cv_lib_xvidcore_xvid_encore=no
.endif

post-extract:
.if defined(WITH_MUSIC)
.for file in ${ASC_MUSICS}
	@${TAR} -C ${DISTDIR}/${DIST_SUBDIR} -cf - ${file} | \
		${TAR} -C ${WRKSRC}/data/music --unlink -xf -
.endfor
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.cpp" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'
	@${FIND} ${WRKSRC} -name "Makefile.in" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|/games/|/|g ; \
		 s|$$(srcdir)/asc_makegfx.6||g'
	@${REINPLACE_CMD} -e \
		's|/games/|/|g ; \
		 s|lua >=|lua-5.1 >=|g ; \
		 /if test/s|==|=|g' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
