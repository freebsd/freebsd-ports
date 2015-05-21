# Created by: pneumann@gmail.com
# $FreeBSD$

PORTNAME=	gimmie
PORTVERSION=	0.2.7
PORTREVISION=	11
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.beatniksoftware.com/gimmie/releases/ \
		LOCAL/beech

MAINTAINER=	pneumann@gmail.com
COMMENT=	Gnome desktop organizer

BROKEN=		Uses unknown GNOME components pygnomedesktop and pygnomeextras
DEPRECATED=	Broken since update to gnome3
EXPIRATION_DATE=	2015-06-02

RUN_DEPENDS=	${LOCALBASE}/lib/libgnomecups-1.0.a:${PORTSDIR}/print/libgnomecups \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/libgmail.py:${PORTSDIR}/mail/py-libgmail
BUILD_DEPENDS=	${LOCALBASE}/lib/libgnomecups-1.0.a:${PORTSDIR}/print/libgnomecups \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:${PORTSDIR}/devel/py-dbus

USE_GNOME=	gnomeprefix pygnome2 pygnomedesktop pygnomeextras
USES=		gmake libtool pathfix pkgconfig python
GCONF_SCHEMAS=	gimmie.schemas
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
NO_PO=	yes
.endif

.include <bsd.port.mk>
