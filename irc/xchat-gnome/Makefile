# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	xchat
PORTVERSION=	0.26.1
PORTREVISION=	7
CATEGORIES=	irc gnome ipv6
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/xchat-gnome/${PORTVERSION:R}
PKGNAMESUFFIX=	-gnome
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	An IRC client for GNOME 2 (development version)

LIB_DEPENDS=	sexy:${PORTSDIR}/x11-toolkits/libsexy \
		canberra-gtk:${PORTSDIR}/audio/libcanberra \
		notify:${PORTSDIR}/devel/libnotify

USE_BZIP2=	yes
USES=		pathfix desktop-file-utils gettext gmake pkgconfig
USE_GNOME=	gnomeprefix libgnomeui gnomedocutils
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
GCONF_SCHEMAS=	apps_xchat.schemas notification.schemas urlscraper.schemas
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

MAN1=		xchat-gnome.1

OPTIONS_DEFINE=	DBUS IPV6 PYTHON PERL TCL
OPTIONS_DEFAULT=DBUS IPV6 PERL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-dbus
USE_GNOME+=	gconf2
GCONF_SCHEMAS+=	url_handler.schemas
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=		PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MTCL}
USE_TCL=	84
CONFIGURE_ARGS+=--enable-tcl=${TCL_LIBDIR}
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} \
		-L${TCL_LIBDIR}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} \
		-I${TCL_INCLUDEDIR}
PLIST_SUB+=	TCL=""
.else
CONFIGURE_ARGS+=--disable-tcl
PLIST_SUB+=	TCL="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=	yes
CONFIGURE_ARGS+=--enable-perl
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=--disable-perl
PLIST_SUB+=	PERL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's|PY_LIBS=.*|PY_LIBS="-L\$$PY_EXEC_PREFIX/lib/python\$$PY_VER/config -lpython\$$PY_VER ${PTHREAD_LIBS} -lutil"|' \
		-e 's|tcl-8.4/lib|lib/tcl8.4|g' \
		-e 's|-DGTK_DISABLE_DEPRECATED||g' \
		-e 's|-DGDK_DISABLE_DEPRECATED||g' \
		-e 's|-fgnu89-inline||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
