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
USES=		gettext
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_SQLITE=	yes
INSTALLS_ICONS=	yes
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS MPD XMMS2 AMAROK
MPD_DESC=	Enable MPD support
XMMS2_DESC=	Enable XMMS2 support
AMAROK_DESC=	Enable Amarok 1.4 support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPD}
LIB_DEPENDS+=	mpd:${PORTSDIR}/audio/libmpd
.else
CONFIGURE_ARGS+=	--disable-mpd
.endif

.if ${PORT_OPTIONS:MXMMS2}
LIB_DEPENDS+=	xmmsclient:${PORTSDIR}/audio/xmms2
.else
CONFIGURE_ARGS+=	--disable-xmms2
.endif

.if ${PORT_OPTIONS:MAMAROK}
CONFIGURE_ARGS+=	--enable-amarok1
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
