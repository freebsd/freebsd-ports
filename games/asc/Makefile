# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asc
PORTVERSION=	2.6.0.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}-hq/ASC%20Source/${PORTVERSION:R} \
		http://www.asc-hq.org/music/:music
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ASC_MUSICS:S/$/:music/}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Turn based, multiplayer strategic game with nice graphics

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libboost_regex.so:${PORTSDIR}/devel/boost-libs \
		libsigc-1.2.so:${PORTSDIR}/devel/libsigc++12 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libloki.so:${PORTSDIR}/devel/loki

OPTIONS_DEFINE=	MUSIC XVID
MUSIC_DESC=	Install extra music files

USES=		gmake libtool lua:51 perl5 pkgconfig tar:bzip2
USE_SDL=	image mixer sound sdl
USE_WX=		3.0
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
USE_PERL5=	build
GNU_CONFIGURE=	yes

CFLAGS+=	-D_UNICODE_BROKEN_
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
		share/appdata/asc.appdata.xml
PORTDATA=	*

DESKTOP_ENTRIES="Advanced Strategic Command" "Turn based strategic game" "" \
		"${PORTNAME}" "" ""

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXVID}
LIB_DEPENDS+=	libxvidcore.so:${PORTSDIR}/multimedia/xvid
.else
CONFIGURE_ENV+=	ac_cv_lib_xvidcore_xvid_encore=no
.endif

.if ${PORT_OPTIONS:MMUSIC}
ASC_MUSICS=	frontiers.ogg time_to_strike.ogg machine_wars.ogg

post-extract:
.for i in ${ASC_MUSICS}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}/data/music
.endfor
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|/games/|/|g'
	@${REINPLACE_CMD} -e \
		's|/games/|/|g ; \
		 s|lua >=|lua-5.1 >=|g ; \
		 /if test/s|==|=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|? 0 :|? (void)0 :|' ${WRKSRC}/source/errors.h

.include <bsd.port.mk>
