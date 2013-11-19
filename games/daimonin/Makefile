# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	daimonin
PORTVERSION=	0.10.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://daimonin.svn.sourceforge.net/viewvc/daimonin/main/client/?view=tar&pathrev=${SVN_REVISION}&file=
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free open source Massively Multiplayer On-line Role-playing Game (MMORPG)

LIB_DEPENDS=	physfs.1:${PORTSDIR}/devel/physfs \
		curl:${PORTSDIR}/ftp/curl

SVN_REVISION=	6021
FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-simplelayout --enable-getaddrinfo
LDFLAGS+=	-L${LOCALBASE}/lib
USE_AUTOTOOLS=	automake autoconf
USE_SDL=	mixer image
SUB_FILES=	daimonin.sh
SUB_LIST=	PORTVERSION=${PORTVERSION}

WRKSRC=		${WRKDIR}/client/make/linux

OPTIONS_DEFINE=	MUSIC DEBUG
OPTIONS_SINGLE=	KB
OPTIONS_SINGLE_KB=	KB_DESKTOP KB_LAPTOP KB_ROGUE
KB_DESKTOP_DESC=	Key bindings for desktop (num keypad)
KB_LAPTOP_DESC=	Key bindings for laptop (789uojkl)
KB_ROGUE_DESC=	Rogue-like key bindings (hjkl and yubn)
KB_DESC=	KB Selection
MUSIC_DESC=	Download and Install music files (83 Mb)

OPTIONS_DEFAULT=	KB_DESKTOP MUSIC

DD?=		/bin/dd

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-wrapper.c
.endif

.if ${PORT_OPTIONS:MMUSIC}
DEPRECATED=	Depends on expired games/daimonin-music
EXPIRATION_DATE=2013-12-19
RUN_DEPENDS+=	${DATADIR}/media/AnichGiantTrouble.ogg:${PORTSDIR}/games/daimonin-music
.endif

post-fetch-script:
	@# the downloaded .tar.gz DISTFILE is regenerated for each download, so contains a different timestamp each time
	@# clear the timestamp here so the checksum works
	@${PRINTF} '\0\0\0\0' | ${DD} of=${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} bs=1w count=1 seek=1 conv=notrunc 2>/dev/null

pre-patch:
	${CP} ${WRKSRC}/../../settings/keys-laptop.dat ${WRKSRC}/../../settings/keys-rogue.dat

post-patch:
	@${CHMOD} a+x ${WRKSRC}/make_utils/install-sh
	@${CP} ${PORTSDIR}/Templates/config.guess ${PORTSDIR}/Templates/config.sub \
		${WRKSRC}/make_utils/

pre-configure:
	cd ${WRKSRC}; ${LN} -sf ${AUTOMAKE_DIR}/COPYING . && ${AUTORECONF}

post-install:
	${MV} ${PREFIX}/bin/daimonin ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/daimonin.sh ${PREFIX}/bin/daimonin
	${CHMOD} a+x ${PREFIX}/bin/daimonin
	@${FIND} ${DATADIR} -name '*.orig' -exec rm {} \;
	${MV} ${DATADIR}/settings/keys.dat ${DATADIR}/settings/keys-desktop.dat
.if ${PORT_OPTIONS:MKB_LAPTOP}
	@${ECHO} Configuring keyboard bindings for laptop
	${LN} -s ${DATADIR}/settings/keys-laptop.dat ${DATADIR}/settings/keys.dat
.elif ${PORT_OPTIONS:MKB_ROGUE}
	@${ECHO} Configuring rogue-like keyboard bindings
	${LN} -s ${DATADIR}/settings/keys-rogue.dat ${DATADIR}/settings/keys.dat
.else
	@${ECHO} Configuring keyboard bindings for desktop
	${LN} -s ${DATADIR}/settings/keys-desktop.dat ${DATADIR}/settings/keys.dat
.endif

.include <bsd.port.mk>
