# $FreeBSD$

PORTNAME=	dbus-sharp-glib
PORTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/mono/dbus-sharp/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	D-Bus for .NET: GLib integration module

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-sharp-1.0.pc:${PORTSDIR}/devel/dbus-sharp
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-sharp-1.0.pc:${PORTSDIR}/devel/dbus-sharp

USES=		pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
