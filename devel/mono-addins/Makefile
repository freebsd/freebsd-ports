# $FreeBSD$

PORTNAME=	mono-addins
PORTVERSION=	1.3
PORTREVISION=	1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	devel

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono framework to create extensible applications

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	mono

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_MCS=${LOCALBASE}/bin/mcs
USES=		autoreconf gmake gnome mono pkgconfig

OPTIONS_DEFINE=	GTK2 GTK3
OPTIONS_DEFAULT=GTK2
OPTIONS_SUB=	yes

GTK2_USE=	GNOME=gtksharp20
GTK2_CONFIGURE_ENABLE=	gui

#GTK3_USE=	GNOME=gtksharp30
GTK3_CONFIGURE_ENABLE=	gui-gtk3

PLIST_SUB+=	VER=1.0.0

.include <bsd.port.mk>
