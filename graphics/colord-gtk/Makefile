# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	colord-gtk
PORTVERSION=	0.1.26
CATEGORIES=	graphics
MASTER_SITES=	http://www.freedesktop.org/software/colord/releases/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Manage color profiles to accurately color input/output devices

BUILD_DEPENDS=	colord>=0.1.20:graphics/colord
LIB_DEPENDS=	libcolord.so:graphics/colord \
		libpolkit-gobject-1.so:sysutils/polkit \
		libdbus-1.so:devel/dbus \
		liblcms2.so:graphics/lcms2

USE_GNOME=	gtk30 intlhack introspection:build
USES=		gettext gmake libtool pathfix pkgconfig sqlite tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-gtk-doc-html=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	docbook2html:textproc/docbook-utils \
			docbook-sgml>0:textproc/docbook-sgml

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-Wclobbered||g' \
		-e 's|-Wempty-body||g' \
		-e 's|-Wignored-qualifiers||g' \
		-e 's|-Wtype-limits||g' \
		-e 's|-Wmissing-parameter-type||g' \
		${WRKSRC}/configure

.if ! ${PORT_OPTIONS:MMANPAGES}
	@${REINPLACE_CMD} -e "s|2MAN_TRUE=$$|2MAN_TRUE='#'|g ; \
		s|2MAN_FALSE='#'|2MAN_FALSE=|g" ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
