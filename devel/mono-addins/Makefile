# $FreeBSD$

PORTNAME=	mono-addins
PORTVERSION=	1.1
CATEGORIES=	devel

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono framework to create extensible applications

LICENSE=	MIT

USES=		mono

USE_GITHUB=	yes
GH_ACCOUNT=	mono
GH_TAGNAME=	${DISTNAME}
GH_COMMIT=	64a45d9

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal autoconf automake
ACLOCAL_ARGS=	-I .
AUTOMAKE_ARGS+=	--gnu --add-missing
USES=		gmake pkgconfig
WANT_GNOME=	yes

OPTIONS_DEFINE=	GTK2
OPTIONS_DEFAULT=GTK2

PLIST_SUB+=	VER=1.0.0

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtksharp20
CONFIGURE_ARGS+=	--enable-gui
PLIST_SUB+=	OPT_GTK2=""
.else
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB+=	OPT_GTK2="@comment "
.endif

.include <bsd.port.post.mk>
