# New ports collection makefile for:	exaile
# Date created:		19 December 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	exaile
DISTVERSION=	0.2.99.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.exaile.org/files/ \
		http://wickedmachine.net/~jsa/FreeBSD/distfiles/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-0.3.0a3

MAINTAINER=	jsa@wickedmachine.net
COMMENT=	AmaroK replacement for GTK+ (developmental series)

RUN_DEPENDS=	py*-mutagen>=1.11:${PORTSDIR}/audio/py-mutagen

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	pygtk2
USE_GSTREAMER=	python good
USE_PYTHON=	2.5+

CONFLICTS=	exaile-0.2.[0-9][0-8]* exaile-0.3.*

# The reality with these options is that they all will be autodetected and used
# if already installed. These just force Exaile to bring them in as well.
OPTIONS=	BAD "Install bad GStreamer plugins" On \
		BDB "Install Python Berkley DB module" On \
		CDDB "Lookup CD information within Exaile" On \
		DBUS "Rely on Python D-Bus bindings" On \
		HAL "Force depend on HAL" On \
		NOTIFY "Enable desktop event notification" On \
		NLS "Native Language Support" On \
		SEXY "UI enhancements"  On

.if !defined(WITHOUT_BAD)
USE_GSTREAMER+=	bad
.endif

.if !defined(WITHOUT_BDB)
RUN_DEPENDS+=	py*-bsddb>=2.5:${PORTSDIR}/databases/py-bsddb
.endif

.if !defined(WITHOUT_CDDB)
RUN_DEPENDS+=	py*-cddb>=1.4:${PORTSDIR}/audio/py-cddb
.endif

.if !defined(WITHOUT_DBUS)
RUN_DEPENDS+=	py*-dbus>=0.82.1:${PORTSDIR}/devel/py-dbus
.endif

.if !defined(WITHOUT_HAL)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.endif

.if !defined(WITHOUT_NOTIFY)
RUN_DEPENDS+=	py*-notify>=0.1.1:${PORTSDIR}/devel/py-notify
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_SEXY)
RUN_DEPENDS+=	py*-sexy>=0.1.9:${PORTSDIR}/x11-toolkits/py-sexy
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(DESTDIR)/etc/xdg|(PREFIX)/etc/xdg|' \
	${WRKSRC}/Makefile

.include <bsd.port.mk>
