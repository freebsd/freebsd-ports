# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osdlyrics
PORTVERSION=	0.4.3
PORTREVISION=	1
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
USES=		gettext gmake iconv pkgconfig
USE_GNOME=	gtk20
USE_SQLITE=	yes
INSTALLS_ICONS=	yes
PORTDOCS=	AUTHORS ChangeLog NEWS README
LDFLAGS=	-liconv

OPTIONS_DEFINE=	DOCS MPD XMMS2 AMAROK
MPD_DESC=	Enable MPD support
XMMS2_DESC=	Enable XMMS2 support
AMAROK_DESC=	Enable Amarok 1.4 support

MPD_LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd
MPD_CONFIGURE_OFF=	--disable-mpd
XMMS2_LIB_DEPENDS=	xmmsclient:${PORTSDIR}/audio/xmms2
XMMS2_CONFIGURE_OFF=	--disable-xmms2
AMAROK_CONFIGURE_ENABLE=	amarok1

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
