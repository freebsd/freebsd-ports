# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	tomboy
PORTVERSION=	1.15.4
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Personal note taking system for the GNOME desktop

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-sharp-glib-1.0.pc:devel/dbus-sharp-glib \
		mautil:devel/mono-addins
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-sharp-glib-1.0.pc:devel/dbus-sharp-glib \
		mautil:devel/mono-addins

USES=		cpe gettext gmake libtool mono pathfix pkgconfig tar:xz
USE_GNOME=	intlhack gnomeprefix gnomedocutils gnomesharp20
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	tomboy.schemas
CPE_VENDOR=	gnome

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	EVOLUTION
EVOLUTION_DESC=	Build evolution addin

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MEVOLUTION}
CONFIGURE_ARGS+=--enable-evolution
BUILD_DEPENDS+=	${LOCALBASE}/lib/mono/gmime-sharp-2.6/gmime-sharp.dll:mail/gmime26-sharp
RUN_DEPENDS+=	${LOCALBASE}/lib/mono/gmime-sharp-2.6/gmime-sharp.dll:mail/gmime26-sharp
PLIST_SUB+=	EVOLUTION=""
.else
CONFIGURE_ARGS+=--disable-evolution
PLIST_SUB+=	EVOLUTION="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/Tomboy/tomboy*.in

.include <bsd.port.post.mk>
