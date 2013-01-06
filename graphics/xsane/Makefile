# Created by: Dominik Brettnacher <domi@nonsensss.de>
# $FreeBSD$

PORTNAME=	xsane
PORTVERSION=	0.998
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.xsane.org/download/ \
		http://gd.tuwien.ac.at/hci/sane/xsane/ \
		ftp://ftp.mostang.com/pub/sane/xsane/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk-based X11 frontend for SANE (Scanner Access Now Easy)

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		sane:${PORTSDIR}/graphics/sane-backends

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GNOME=	gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		xsane.1

#SUB_FILES+=	pkg-message

OPTIONS_DEFINE=	GIMP NLS
GIMP_DESC=	GIMP plugin support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -lintl"
.endif

.if ${PORT_OPTIONS:MGIMP}
SUB_FILES+=	pkg-message
LIB_DEPENDS+=	gimp:${PORTSDIR}/graphics/gimp-app
.else
CONFIGURE_ARGS+=	--disable-gimp
.endif

pre-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} \
		-i "" -e 's|\$$(DESTDIR)\$$(sbindir)||g'

post-install:
.if ${PORT_OPTIONS:MGIMP}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
