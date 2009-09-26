# New ports collection makefile for:	springlobby
# Date created:		02 Sep 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	springlobby
PORTVERSION=	0.23
CATEGORIES=	games net
MASTER_SITES=	http://www.springlobby.info/tarballs/ \
		http://mirror.amdmi3.ru/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform lobby client for the Spring RTS project

RUN_DEPENDS=	spring:${PORTSDIR}/games/spring

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_WX=		2.8+
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	*

OPTIONS=	TORRENT	"Support automatic content downloads via torrent" on \
		SOUND	"Enable sound" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_TORRENT)
LIB_DEPENDS+=	torrent.1:${PORTSDIR}/net-p2p/rblibtorrent
.else
CONFIGURE_ARGS+=--disable-torrent-system
.endif

.if !defined(WITHOUT_SOUND)
USE_SDL+=	sdl mixer
.else
CONFIGURE_ARGS+=--disable-sound
.endif

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
