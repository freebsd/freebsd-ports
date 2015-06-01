# Created by: Alexander Kojevnikov <alexander@kojevnikov.com>
# $FreeBSD$

PORTNAME=	pinta
PORTVERSION=	1.5
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/PintaProject/Pinta/releases/download/1.5/

MAINTAINER=	david.vionnet@vmailbox.org
COMMENT=	Simple Gtk\# Paint Program

LICENSE=	MIT

BROKEN=		Fails to build with mono 4

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:${PORTSDIR}/devel/mono-addins
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		desktop-file-utils gmake mono pkgconfig
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

USE_GNOME=	gtksharp20
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
