# Created by: Dominik Brettnacher <domi@nonsensss.de>
# $FreeBSD$

PORTNAME=	xsane
PORTVERSION=	0.998
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.xsane.org/download/ \
		http://gd.tuwien.ac.at/hci/sane/xsane/ \
		ftp://ftp.mostang.com/pub/sane/xsane/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Gtk-based X11 frontend for SANE (Scanner Access Now Easy)

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff
BUILD_DEPENDS=	scanimage:${PORTSDIR}/graphics/sane-backends
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		xsane.1

OPTIONS_DEFINE=	GIMP NLS
GIMP_DESC=	GIMP plugin support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -lintl"
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGIMP}
SUB_FILES+=	pkg-message
LIB_DEPENDS+=	gimp:${PORTSDIR}/graphics/gimp-app
CONFIGURE_ARGS+=--enable-gimp2
.else
CONFIGURE_ARGS+=--disable-gimp
.endif

pre-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} \
		-i "" -e 's|\$$(DESTDIR)\$$(sbindir)||g'

post-install:
.if ${PORT_OPTIONS:MGIMP}
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif

.include <bsd.port.mk>
