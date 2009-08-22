# New ports collection makefile for:	tmw
# Date created:				12 Oktober 2005
# Whom:					Tobias Gion
#
# $FreeBSD$
#

PORTNAME=	tmw
PORTVERSION=	0.0.29.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/themanaworld/The%20Mana%20World/${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A free open source 2D MMORPG in development

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		png.5:${PORTSDIR}/graphics/png \
		curl.5:${PORTSDIR}/ftp/curl \
		physfs.1:${PORTSDIR}/devel/physfs
BUILD_DEPENDS=	guichan>=0.8.1:${PORTSDIR}/devel/guichan
RUN_DEPENDS=	guichan>=0.8.1:${PORTSDIR}/devel/guichan

GNU_CONFIGURE=	yes
USE_SDL=	sdl image mixer net ttf

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `${SDL_CONFIG} --cflags` ${PTHREAD_CFLAGS}"
MAN6=		tmw.6

OPTIONS=	MUSIC	"Install additional music" on \
		NLS	"Enable gettext support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lintl"
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
.endif

.if !defined(WITHOUT_MUSIC)
MUSICNAME=	tmwmusic-0.2
MUSICSUBDIR=	data/music
DISTFILES+=	${MUSICNAME}.tar.gz
MUSICDIR=	${WRKDIR}/${MUSICNAME}/${MUSICSUBDIR}
PLIST_SUB+=	MUSICADDON=""
.else
PLIST_SUB+=	MUSICADDON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's|SUBDIRS = data docs po src|SUBDIRS = data docs src|g' ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(WITHOUT_MUSIC)
	${MKDIR} ${DATADIR}/data/music
	${FIND} -E ${MUSICDIR} -type f -iregex ".*\.ogg" \
		-exec ${INSTALL_DATA} "{}" "${DATADIR}/${MUSICSUBDIR}" \;
.endif

.include <bsd.port.post.mk>
