# $FreeBSD$

PORTNAME=	gobby
PORTVERSION=	0.4.13
CATEGORIES=	editors
MASTER_SITES=	http://releases.0x539.de/gobby/ \
		LOCAL/${MAINTAINER:C/([^@]*)@.*/\1/}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	A free collaborative editor

LICENSE=	GPLv2

LIB_DEPENDS=	obby-0.4.1:${PORTSDIR}/devel/obby \
		net6-1.3.0:${PORTSDIR}/net/net6 \
		xml++-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

OPTIONS_DEFINE=	GTKSPELL NLS
GTKSPELL_DESC=	Enable GtkSpell support

USE_GNOME=	gnomehack gtksourceview2 intltool
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

MAN1=		${PORTNAME}.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=	gtkspell:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=--with-gtkspell
.else
CONFIGURE_ARGS+=--without-gtkspell
.endif

.if ${PORT_OPTIONS:MNLS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ARGS+=	--enable-nls
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
