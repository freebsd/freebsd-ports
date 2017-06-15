# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osdlyrics
PORTVERSION=	0.4.3
PORTREVISION=	5
CATEGORIES=	audio deskutils
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/osd-lyrics/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	On-screen lyrics display program for various media players

LICENSE=	GPLv3

LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libdbus-glib-1.so:devel/dbus-glib \
		libcurl.so:ftp/curl

USES=		desktop-file-utils gettext gmake iconv localbase pkgconfig sqlite
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS MPD XMMS2 AMAROK

MPD_DESC=	MPD support
XMMS2_DESC=	XMMS2 support
AMAROK_DESC=	Amarok 1.4 support

MPD_LIB_DEPENDS=	libmpd.so:audio/libmpd
MPD_CONFIGURE_OFF=	--disable-mpd

XMMS2_LIB_DEPENDS=	libxmmsclient.so:audio/xmms2
XMMS2_CONFIGURE_OFF=	--disable-xmms2

AMAROK_CONFIGURE_ON=	--enable-amarok1

post-patch:
.for i in src/Makefile.in src/tests/Makefile.in
	@${REINPLACE_CMD} -e '/-lstdc++/d' -e '/^CCLD =/s/=.*/= $$(CXX)/' \
		${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e '/-O2/d' ${WRKSRC}/lib/chardetect/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
