# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asc
PORTVERSION=	2.6.1.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}-hq/ASC%20Source/${PORTVERSION:R} \
		http://www.asc-hq.org/music/:music
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Turn based, multiplayer strategic game with nice graphics

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:archivers/zip
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libboost_regex.so:devel/boost-libs \
		libsigc-2.0.so:devel/libsigc++20 \
		libexpat.so:textproc/expat2 \
		libloki.so:devel/loki

USES=		compiler:c++11-lib gmake libtool lua perl5 pkgconfig tar:bzip2
USE_CXXSTD=	c++11
USE_SDL=	image mixer sound sdl
USE_WX=		3.0
WX_CONF_ARGS=	absolute
USE_PERL5=	build
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/asc \
		bin/asc_demount \
		bin/asc_mapedit \
		bin/asc_mount \
		bin/asc_weaponguide \
		man/man6/asc.6.gz \
		man/man6/asc_demount.6.gz \
		man/man6/asc_mapedit.6.gz \
		man/man6/asc_mount.6.gz \
		man/man6/asc_weaponguide.6.gz \
		share/appdata/asc.appdata.xml \
		${DATADIR}/asc2_dlg.zip \
		${DATADIR}/main.ascdat

DESKTOP_ENTRIES="Advanced Strategic Command" "Turn based strategic game" "" \
		"${PORTNAME}" "" ""

OPTIONS_DEFINE=		MUSIC XVID

MUSIC_DESC=		Install extra music files
MUSIC_DISTFILES=	${ASC_MUSICS:S,$,:music,}
MUSIC_PLIST_FILES=	${ASC_MUSICS:S,^,%%DATADIR%%/music/,}
XVID_LIB_DEPENDS=	libxvidcore.so:multimedia/xvid
XVID_CONFIGURE_ENV_OFF=	ac_cv_lib_xvidcore_xvid_encore=no
ASC_MUSICS=		frontiers.ogg time_to_strike.ogg machine_wars.ogg

post-extract-MUSIC-on:
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${ASC_MUSICS} \
		${WRKSRC}/data/music)

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|/games/|/|g'
	@${REINPLACE_CMD} -e \
		's|/games/|/|g ; \
		 s|lua >= 5.1 |lua-${LUA_VER}|g ;\
		 /if test/s|==|=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|? 0 :|? (void)0 :|' ${WRKSRC}/source/errors.h
	@${REINPLACE_CMD} -e \
		's|tAttackH|AttackH|' ${WRKSRC}/source/actions/vehicleattack.h

.include <bsd.port.mk>
