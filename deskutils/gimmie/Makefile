# New ports collection makefile for:    gimmie
# Date created:                         28 06 2006
# Whom:                                 pneumann@gmail.com
#
# $FreeBSD$
#

PORTNAME=	gimmie
PORTVERSION=	0.2.7
PORTREVISION=	7
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.beatniksoftware.com/gimmie/releases/ \
		LOCAL/beech

MAINTAINER=	pneumann@gmail.com
COMMENT=	Gnome desktop organizer

RUN_DEPENDS=	${LOCALBASE}/lib/libgnomecups-1.0.a:${PORTSDIR}/print/libgnomecups \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/libgmail.py:${PORTSDIR}/mail/py-libgmail
BUILD_DEPENDS=	${LOCALBASE}/lib/libgnomecups-1.0.a:${PORTSDIR}/print/libgnomecups \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:${PORTSDIR}/devel/py-dbus

USE_GNOME=	gnomehack gnometarget gnomeprefix pygnome2 pygnomedesktop pygnomeextras
USE_GMAKE=	yes
USE_PYTHON=	yes
GCONF_SCHEMAS=	gimmie.schemas
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
NO_PO=	yes
.endif

.include <bsd.port.mk>
