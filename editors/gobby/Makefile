# $FreeBSD$

PORTNAME=	gobby
PORTVERSION=	0.4.13
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://releases.0x539.de/gobby/ \
		LOCAL/${MAINTAINER:C/([^@]*)@.*/\1/}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Free collaborative editor

LICENSE=	GPLv2

LIB_DEPENDS=	libobby.so:${PORTSDIR}/devel/obby \
		libnet6.so:${PORTSDIR}/net/net6 \
		libxml++-2.6.so:${PORTSDIR}/textproc/libxml++26 \
		libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24

OPTIONS_DEFINE=	GTKSPELL NLS
GTKSPELL_DESC=	Enable GtkSpell support

USE_GNOME=	gtksourceview2 intltool
USES=		gmake pkgconfig pathfix
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=	libgtkspell.so:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=--with-gtkspell
.else
CONFIGURE_ARGS+=--without-gtkspell
.endif

.if ${PORT_OPTIONS:MNLS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ARGS+=	--enable-nls
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
