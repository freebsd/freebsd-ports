# New ports collection makefile for:	OSD Lyrics
# Date created:				18 Nov 2011
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osdlyrics
PORTVERSION=	0.4.1
CATEGORIES=	audio deskutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	osd-lyrics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	On-screen lyrics display program for various media players

LICENSE=	GPLv3

LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		curl.6:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	DATADIRNAME=share
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_SQLITE=	yes
INSTALLS_ICONS=	yes
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS=	MPD	"Enable MPD support"		off \
		XMMS2	"Enable XMMS2 support"		off \
		AMAROK	"Enable Amarok 1.4 support"	off

.include <bsd.port.options.mk>

.if defined(WITH_MPD)
LIB_DEPENDS+=	mpd.3:${PORTSDIR}/audio/libmpd
.else
CONFIGURE_ARGS+=	--disable-mpd
.endif

.if defined(WITH_XMMS2)
LIB_DEPENDS+=	xmmsclient.6:${PORTSDIR}/audio/xmms2
.else
CONFIGURE_ARGS+=	--disable-xmms2
.endif

.if defined(WITH_AMAROK)
CONFIGURE_ARGS+=	--enable-amarok1
.endif

post-patch:
# Fix compilation warnings to unbreak the build with -Werror
	@${REINPLACE_CMD} -E 's/(char \*in = inbuf),/const \1; char/' \
		${WRKSRC}/src/ol_lrc_parser.c
	@${REINPLACE_CMD} -e '/convert/s/char \*src/const &/' -e \
		's/char \*\*input/const &/' \
			${WRKSRC}/src/ol_lrc_fetch_utils.[ch]
	@${REINPLACE_CMD} -e 's/GdkColor ret/& = { .pixel = 0 }/' \
		${WRKSRC}/src/ol_option.c
	@${REINPLACE_CMD} -e 's/static const gboolean/static gboolean/' \
		${WRKSRC}/src/ol_player_muine.c
	@${REINPLACE_CMD} -e \
		'/!ol_player_amarok1_get_uint/s/[^ ]*))/(guint *)&/' \
			${WRKSRC}/src/ol_player_amarok1.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
