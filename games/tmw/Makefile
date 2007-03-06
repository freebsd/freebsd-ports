# New ports collection makefile for:	tmw
# Date created:				12 Oktober 2005
# Whom:					Tobias Gion
#
# $FreeBSD$
#

PORTNAME=	tmw
PORTVERSION=	0.0.22.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	themanaworld
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mva@sysfault.org
COMMENT=	A free open source 2D MMORPG in development

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		png.5:${PORTSDIR}/graphics/png \
		curl.4:${PORTSDIR}/ftp/curl \
		physfs-1.0.1:${PORTSDIR}/devel/physfs
BUILD_DEPENDS=	guichan>=0.6.0:${PORTSDIR}/devel/guichan
RUN_DEPENDS=	guichan>=0.6.0:${PORTSDIR}/devel/guichan

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl image mixer net
USE_GCC=	3.2+
USE_GETOPT_LONG=yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `${SDL_CONFIG} --cflags` -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

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
