# New ports collection makefile for:	OSD Lyrics
# Date created:				18 Nov 2011
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osdlyrics
PORTVERSION=	0.4.3
CATEGORIES=	audio deskutils
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	osd-lyrics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	On-screen lyrics display program for various media players

LICENSE=	GPLv3

LIB_DEPENDS=	notify:${PORTSDIR}/devel/libnotify \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	DATADIRNAME=share
# Cannot enable -Werror yet: Clang does not like the code `printf(_("..."))',
# see this bug for details: http://llvm.org/bugs/show_bug.cgi?id=3814
#CONFIGURE_ARGS=	--with-werror
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
LIB_DEPENDS+=	mpd:${PORTSDIR}/audio/libmpd
.else
CONFIGURE_ARGS+=	--disable-mpd
.endif

.if defined(WITH_XMMS2)
LIB_DEPENDS+=	xmmsclient:${PORTSDIR}/audio/xmms2
.else
CONFIGURE_ARGS+=	--disable-xmms2
.endif

.if defined(WITH_AMAROK)
CONFIGURE_ARGS+=	--enable-amarok1
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
