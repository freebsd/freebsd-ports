# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	colord
PORTVERSION=	1.2.11
CATEGORIES=	graphics
MASTER_SITES=	http://www.freedesktop.org/software/colord/releases/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Manage color profiles to accurately color input/output devices

BUILD_DEPENDS=	spotread:${PORTSDIR}/graphics/argyllcms
LIB_DEPENDS=	libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		liblcms2.so:${PORTSDIR}/graphics/lcms2
RUN_DEPENDS=	spotread:${PORTSDIR}/graphics/argyllcms

USERS=		colord
GROUPS=		colord

USES=		gettext gmake libtool pathfix pkgconfig sqlite tar:xz
USE_GNOME=	glib20 intlhack introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes
CONFIGURE_ARGS=	--disable-udev \
		--localstatedir=/var \
		--enable-gtk-doc-html=no \
		--disable-bash-completion \
		--disable-gusb \
		--disable-sane \
		--with-daemon-user=colord \
		--disable-systemd-login
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	USB_CFLAGS="-I/usr/include" \
		USB_LIBS="-L/usr/lib -lusb"
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.freedesktop.ColorHelper.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	MANPAGES PPROFILES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	docbook2html:${PORTSDIR}/textproc/docbook-utils \
			docbook-sgml>0:${PORTSDIR}/textproc/docbook-sgml
PPROFILES_DESC=		Build extra print profiles (long build time)
PPROFILES_CONFIGURE_ENABLE=	print-profiles

.include <bsd.port.options.mk>

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
		${WRKSRC}/lib/colord/cd-icc-store.c \
		${WRKSRC}/src/cd-profile.c
.if ! ${PORT_OPTIONS:MMANPAGES}
	@${REINPLACE_CMD} -e "s|2MAN_TRUE=$$|2MAN_TRUE='#'|g ; \
		s|2MAN_FALSE='#'|2MAN_FALSE=|g" ${WRKSRC}/configure
.endif

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/colord/icc

.include <bsd.port.mk>
