# Created by: Alexander Kojevnikov <alexander@kojevnikov.com>
# $FreeBSD$

PORTNAME=	pinta
PORTVERSION=	1.4
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/PintaProject/Pinta/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Gtk\# Paint Program

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:${PORTSDIR}/devel/mono-addins
RUN_DEPENDS:=	${BUILD_DEPENDS}

BROKEN=		Does not build
GNU_CONFIGURE=	yes
USE_GNOME=	gtksharp20
INSTALLS_ICONS=	yes
USES=		desktop-file-utils gettext gmake mono pkgconfig

MAN1=		pinta.1
MANCOMPRESSED=	yes

NO_STAGE=	yes
post-install:
	-@update-desktop-database

.include <bsd.port.mk>
