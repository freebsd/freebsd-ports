# New ports collection makefile for:	tmw
# Date created:				12 Oktober 2005
# Whom:					Tobias Gion
#
# $FreeBSD$
#

PORTNAME=	tmw
PORTVERSION=	0.0.25
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	themanaworld
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mva@sysfault.org
COMMENT=	A free open source 2D MMORPG in development

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		png.5:${PORTSDIR}/graphics/png \
		curl.4:${PORTSDIR}/ftp/curl \
		physfs-1.0.1:${PORTSDIR}/devel/physfs
BUILD_DEPENDS=	guichan>=0.8.1:${PORTSDIR}/devel/guichan
RUN_DEPENDS=	guichan>=0.8.1:${PORTSDIR}/devel/guichan

GNU_CONFIGURE=	yes
USE_SDL=	sdl image mixer net

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `${SDL_CONFIG} --cflags` ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAN6=		tmw.6

OPTIONS=	MUSIC	"Install additional music" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MUSIC)
MUSICNAME=	tmwmusic-0.0.20
MUSICSUBDIR=	data/music
DISTFILES+=	${MUSICNAME}.tar.gz
MUSICDIR=	${WRKDIR}/${MUSICNAME}/${MUSICSUBDIR}
PLIST_SUB+=	MUSICADDON=""
.else
PLIST_SUB+=	MUSICADDON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
.if !defined(WITHOUT_MUSIC)
	${MKDIR} ${DATADIR}/data/music
	${FIND} -E ${MUSICDIR} -type f -iregex ".*\.ogg" \
		-exec ${INSTALL_DATA} "{}" "${DATADIR}/${MUSICSUBDIR}" \;
.endif

.include <bsd.port.post.mk>
