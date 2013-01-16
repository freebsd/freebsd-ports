# $FreeBSD$

PORTNAME=	homebank
PORTVERSION=	4.5
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Free, easy, personal accounting for everyone

LICENSE=	GPLv2

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		osp:${PORTSDIR}/textproc/opensp \
		xcb:${PORTSDIR}/x11/libxcb \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_XORG=	pixman x11 xau xcomposite xcursor xdamage xdmcp xext xfixes \
		xi xinerama xrandr xrender
USE_GNOME=	desktopfileutils gnomehier gtk20
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=	OFX
OFX_DESC=	Enable libOFX support
OPTIONS_DEFAULT=OFX

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOFX}
LIB_DEPENDS+=	ofx:${PORTSDIR}/finance/libofx
CONFIGURE_ARGS+=--with-ofx
.else
CONFIGURE_ARGS+=--without-ofx
.endif

post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/install-sh

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@-update-desktop-database
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
