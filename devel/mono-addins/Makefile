# $FreeBSD$

PORTNAME=	mono-addins
PORTVERSION=	1.1
CATEGORIES=	devel

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono framework to create extensible applications

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	mono
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
USES=		autoreconf gmake mono pkgconfig
WANT_GNOME=	yes

OPTIONS_DEFINE=	GTK2
OPTIONS_DEFAULT=GTK2

GTK2_USE=	GNOME=gtksharp20
GTK2_CONFIGURE_ENABLE=	gui
OPTIONS_SUB=	yes

PLIST_SUB+=	VER=1.0.0

.include <bsd.port.mk>
