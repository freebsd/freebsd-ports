PORTNAME=	colord
PORTVERSION=	1.3.5
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://www.freedesktop.org/software/colord/releases/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Manage color profiles to accurately color input/output devices

LICENSE=	GPLv2

BUILD_DEPENDS=	spotread:graphics/argyllcms
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		liblcms2.so:graphics/lcms2
RUN_DEPENDS=	spotread:graphics/argyllcms

USERS=		colord
GROUPS=		colord

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig sqlite \
		tar:xz
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
		--disable-systemd-login \
		--enable-libcolordcompat
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.freedesktop.ColorHelper.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	POLKIT MANPAGES PPROFILES VALA
OPTIONS_DEFAULT=POLKIT VALA

PPROFILES_DESC=	Build extra print profiles (long build time)
POLKIT_DESC=	Build with Polkit support
VALA_DESC=	Build Vala language bindings

POLKIT_LIB_DEPENDS=		libpolkit-gobject-1.so:sysutils/polkit
POLKIT_CONFIGURE_ENABLE=	polkit

MANPAGES_BUILD_DEPENDS=		docbook2html:textproc/docbook-utils \
				docbook-sgml>0:textproc/docbook-sgml
PPROFILES_CONFIGURE_ENABLE=	print-profiles
VALA_CONFIGURE_ENABLE=		vala
VALA_BUILD_DEPENDS=		vapigen:lang/vala
MAKE_ENV=		PYTHONDONTWRITEBYTECODE=1

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-Wclobbered||g' \
		-e 's|-Wempty-body||g' \
		-e 's|-Wignored-qualifiers||g' \
		-e 's|-Wtype-limits||g' \
		-e 's|-Wmissing-parameter-type||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|lib/color|db/color|g' \
		-e 's|/usr/share/color|${PREFIX}/share/color|g' \
		${WRKSRC}/src/cd-main.c \
		${WRKSRC}/lib/colord/cd-icc-store.c \
		${WRKSRC}/src/cd-profile.c
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/lib/colord/cd-edid.c
.if ! ${PORT_OPTIONS:MMANPAGES}
	@${REINPLACE_CMD} -e "s|2MAN_TRUE=$$|2MAN_TRUE='#'|g ; \
		s|2MAN_FALSE='#'|2MAN_FALSE=|g" ${WRKSRC}/configure
.endif

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/colord/icc

.include <bsd.port.mk>
