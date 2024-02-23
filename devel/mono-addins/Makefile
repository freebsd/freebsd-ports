PORTNAME=	mono-addins
PORTVERSION=	1.3
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	5
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mono framework to create extensible applications
WWW=		https://www.mono-project.com/Mono.Addins

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	mono

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
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
