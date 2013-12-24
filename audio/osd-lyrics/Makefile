# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osdlyrics
PORTVERSION=	0.4.3
PORTREVISION=	2
CATEGORIES=	audio deskutils
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	osd-lyrics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	On-screen lyrics display program for various media players

LICENSE=	GPLv3

LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libcurl.so:${PORTSDIR}/ftp/curl

USES=		desktop-file-utils gettext gmake iconv pathfix pkgconfig
USE_GNOME=	gtk20
USE_SQLITE=	yes
GNU_CONFIGURE=	yes
# Cannot enable -Werror yet: Clang does not like the code `printf(_("..."))',
# see this bug for details: http://llvm.org/bugs/show_bug.cgi?id=3814
#CONFIGURE_ARGS=	--with-werror
INSTALLS_ICONS=	yes
PORTDOCS=	AUTHORS ChangeLog NEWS README

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

OPTIONS_DEFINE=	DOCS MPD XMMS2 AMAROK
MPD_DESC=	MPD support
XMMS2_DESC=	XMMS2 support
AMAROK_DESC=	Amarok 1.4 support

MPD_LIB_DEPENDS=	libmpd.so:${PORTSDIR}/audio/libmpd
MPD_CONFIGURE_OFF=	--disable-mpd

XMMS2_LIB_DEPENDS=	libxmmsclient.so:${PORTSDIR}/audio/xmms2
XMMS2_CONFIGURE_OFF=	--disable-xmms2

AMAROK_CONFIGURE_ENABLE=	amarok1

.include <bsd.port.options.mk>

post-patch:
.for i in src/Makefile.in src/tests/Makefile.in
	@${REINPLACE_CMD} -e \
		'/-lstdc++/d' ${WRKSRC}/${i}
.endfor
.for i in lib/chardetect/Makefile.in
	@${REINPLACE_CMD} -e \
		'/-O2/d' ${WRKSRC}/${i}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
