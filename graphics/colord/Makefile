# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/colord/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	colord
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.freedesktop.org/software/colord/releases/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Manage color profiles to accurately color input/output devices

LIB_DEPENDS=	libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		liblcms2.so:${PORTSDIR}/graphics/lcms2

USERS=		colord
GROUPS=		colord

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomehier glib20 intlhack introspection:build
USE_SQLITE=	3
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes
CONFIGURE_ARGS=	--disable-gudev \
		--enable-gtk-doc-html=no \
		--disable-bash-completion \
		--disable-gusb \
		--disable-sane \
		--with-daemon-user=colord \
		--disable-systemd-login
# takes ages we don't want to wait.
CONFIGURE_ARGS+=--disable-print-profiles
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV=	USB_CFLAGS=" " USB_LIBS="-lusb"
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.freedesktop.ColorHelper.gschema.xml

OPTIONS_DEFINE=	MANPAGES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	docbook2html:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-sgml
PLIST_SUB+=	MAN=""
.else
PLIST_SUB+=	MAN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wclobbered||g' \
		-e 's|-Wempty-body||g' \
		-e 's|-Wignored-qualifiers||g' \
		-e 's|-Wtype-limits||g' \
		-e 's|-Wmissing-parameter-type||g' \
		-e 's|LIBS="-lusb-1.0|LIBS="-lusb|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|lib/color|db/color|g' \
		-e 's|/usr/share/color|${PREFIX}/share/color|g' \
		${WRKSRC}/src/cd-main.c \
		${WRKSRC}/src/cd-profile-store.c \
		${WRKSRC}/src/cd-profile.c
.if ! ${PORT_OPTIONS:MMANPAGES}
	@${REINPLACE_CMD} -e "s|2MAN_TRUE=$$|2MAN_TRUE='#'|g ; \
		s|2MAN_FALSE='#'|2MAN_FALSE=|g" ${WRKSRC}/configure
.endif

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/colord/icc

.include <bsd.port.mk>
