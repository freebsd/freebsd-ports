# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/graphics/colord/Makefile,v 1.10 2012/12/17 23:50:40 kwm Exp $

PORTNAME=	colord
PORTVERSION=	0.1.20
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.freedesktop.org/software/colord/releases/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Manage color profiles to accurately color input/output devices

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		vala-vapigen>=0.13.0:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	polkit-gobject-1:${PORTSDIR}/sysutils/polkit \
		dbus-1:${PORTSDIR}/devel/dbus \
		lcms2:${PORTSDIR}/graphics/lcms2

USE_XZ=		yes
USE_GNOME=	gnomehier glib20 intlhack
USES=		pathfix gettext
USE_GMAKE=	yes
USE_SQLITE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes
CONFIGURE_ARGS=	--disable-gudev --enable-gtk-doc-html=no --disable-gtk
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	USB_CFLAGS="-I/usr/include" \
		USB_LIBS="-L/usr/lib -lusb"
MAKE_ENV+=	GI_SCANNER_DISABLE_CACHE=yes

OPTIONS_DEFINE=	SANE MANPAGES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSANE}
CONFGIURE_ARGS+=--enable-sane=yes
LIB_DEPENDS+=	sane:${PORTSDIR}/graphics/sane-backends
.else
CONFIGURE_ARGS+=--disable-sane
.endif

.if ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	docbook2html:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410
MAN1=		cd-create-profile.1 cd-fix-profile.1 colormgr.1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wclobbered||g' \
		-e 's|-Wempty-body||g' \
		-e 's|-Wignored-qualifiers||g' \
		-e 's|-Wtype-limits||g' \
		-e 's|-Wmissing-parameter-type||g' \
		-e 's|LIBS="-lusb-1.0|LIBS="-lusb|g' \
		${WRKSRC}/configure
.if !${PORT_OPTIONS:MMANPAGES}
	@${REINPLACE_CMD} -e "s|2MAN_TRUE=$$|2MAN_TRUE='#'|g ; \
		s|2MAN_FALSE='#'|2MAN_FALSE=|g" ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
