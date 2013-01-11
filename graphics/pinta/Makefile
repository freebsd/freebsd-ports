# New ports collection makefile for:	pinta
# Date created:				2011-02-14
# Whom:					Alexander Kojevnikov <alexander@kojevnikov.com>
#
# $FreeBSD$
#

PORTNAME=	pinta
PORTVERSION=	1.4
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/PintaProject/Pinta/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Simple Gtk\# Paint Program

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:${PORTSDIR}/devel/mono-addins
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gtksharp20 desktopfileutils
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes

MAN1=		pinta.1
MANCOMPRESSED=	yes

post-install:
	-@update-desktop-database

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
