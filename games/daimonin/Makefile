# New ports collection makefile for:	daimonin-client
# Date created:				15 Feb 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	daimonin
PORTVERSION=	0.10.5
CATEGORIES=	games
MASTER_SITES=	http://daimonin.svn.sourceforge.net/viewvc/daimonin/main/client/?view=tar&pathrev=${SVN_REVISION}&file=
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	fbsd@opal.com
COMMENT=	Free open source Massively Multiplayer On-line Role-playing Game (MMORPG)

LIB_DEPENDS=	physfs.1:${PORTSDIR}/devel/physfs \
		curl.6:${PORTSDIR}/ftp/curl

SVN_REVISION=	6021
FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-simplelayout --enable-getaddrinfo
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
USE_AUTOTOOLS=	automake:111 autoconf:268
USE_SDL=	mixer image
SUB_FILES=	daimonin.sh
SUB_LIST=	PORTVERSION=${PORTVERSION}

WRKSRC=		${WRKDIR}/client/make/linux

OPTIONS=	KB_DESKTOP	"Install key bindings for desktop (num keypad)"		on \
		KB_LAPTOP	"Install key bindings for laptop (789uojkl)"		off \
		KB_ROGUE	"Install rogue-like key bindings (hjkl and yubn)"	off \
		MUSIC		"Download and Install music files (83 Mb)"		on \
		DEBUG		"Enable debugging messages in log"			off

DD?=		/bin/dd

.include <bsd.port.pre.mk>

.if defined(WITH_KB_DESKTOP) && defined(WITH_KB_LAPTOP) || \
    defined(WITH_KB_LAPTOP) && defined(WITH_KB_ROGUE) || \
    defined(WITH_KB_DESKTOP) && defined(WITH_KB_ROGUE)
pre-fetch::
	@${ECHO_MSG} 'error: only one of the KB_* OPTIONS may be used - rerun "make config"'
	@${FALSE}
.endif

.if defined(WITH_DEBUG)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-wrapper.c
.endif

.if defined(WITH_MUSIC)
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
.if defined(WITH_KB_LAPTOP)
	@${ECHO} Configuring keyboard bindings for laptop
	${LN} -s ${DATADIR}/settings/keys-laptop.dat ${DATADIR}/settings/keys.dat
.elif defined(WITH_KB_ROGUE)
	@${ECHO} Configuring rogue-like keyboard bindings
	${LN} -s ${DATADIR}/settings/keys-rogue.dat ${DATADIR}/settings/keys.dat
.else
	@${ECHO} Configuring keyboard bindings for desktop
	${LN} -s ${DATADIR}/settings/keys-desktop.dat ${DATADIR}/settings/keys.dat
.endif

.include <bsd.port.post.mk>
