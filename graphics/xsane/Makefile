# New ports collection makefile for:	xsane
# Date created:			Fri Apr  8 00:18:29 MET DST 1999
# Whom:				Dominik Brettnacher <domi@nonsensss.de>
#
# $FreeBSD$
#

PORTNAME=	xsane
PORTVERSION=	0.996
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.xsane.org/download/ \
		http://gd.tuwien.ac.at/hci/sane/xsane/ \
		ftp://ftp.mostang.com/pub/sane/xsane/

MAINTAINER=	domi@nonsensss.de
COMMENT=	Gtk-based X11 frontend for SANE (Scanner Access Now Easy)

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		sane.1:${PORTSDIR}/graphics/sane-backends

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		xsane.1

#SUB_FILES+=	pkg-message

OPTIONS=	GTK2 "Enable GTK2 support (use GTK1 if turned off)" on \
		GIMP "Enable GIMP plugin support" off \
		NLS "Enable Native Language Support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -lintl"
.endif

.if defined(WITHOUT_GTK2)
USE_GNOME=	gtk12
CONFIGURE_ARGS+=	--disable-gtk2
.else
USE_GNOME=	gtk20
.endif

.if defined(WITH_GIMP)
SUB_FILES+=	pkg-message
.if defined(WITHOUT_GTK2)
LIB_DEPENDS+=	gimp:${PORTSDIR}/graphics/gimp1
CONFIGURE_ARGS+=	--disable-gimp2
.else
LIB_DEPENDS+=	gimp:${PORTSDIR}/graphics/gimp-app
.endif # WITHOUT_GTK2
.else
CONFIGURE_ARGS+=	--disable-gimp
.endif

pre-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} \
		-i "" -e 's|\$$(DESTDIR)\$$(sbindir)||g'

post-install:
.if defined(WITH_GIMP)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
