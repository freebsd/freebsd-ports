# $FreeBSD$

PORTNAME=	dbus-sharp-glib
PORTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	GHC

MAINTAINER=	mono@FreeBSD.org
COMMENT=	D-Bus for .NET: GLib integration module

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-sharp-1.0.pc:devel/dbus-sharp
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-sharp-1.0.pc:devel/dbus-sharp

USES=		gmake pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	mono
GH_PROJECT=	dbus-sharp

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GMCS=${LOCALBASE}/bin/mcs
WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.mk>
