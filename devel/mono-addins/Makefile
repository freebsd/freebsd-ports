# $FreeBSD$

PORTNAME=	mono-addins
PORTVERSION=	1.3
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	devel

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono framework to create extensible applications

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	mono

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_MCS=${LOCALBASE}/bin/mcs
USES=		autoreconf gmake mono pkgconfig
WANT_GNOME=	yes

OPTIONS_DEFINE=	GTK2 GTK3
OPTIONS_DEFAULT=GTK2

GTK2_USE=	GNOME=gtksharp20
GTK2_CONFIGURE_ENABLE=	gui
OPTIONS_SUB=	yes

#GTK3_USE=	GNOME=gtksharp30
GTK3_CONFIGURE_ENABLE=	gui-gtk3
OPTIONS_SUB=	yes

PLIST_SUB+=	VER=1.0.0

.include <bsd.port.mk>
