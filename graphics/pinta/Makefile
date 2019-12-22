# Created by: Alexander Kojevnikov <alexander@kojevnikov.com>
# $FreeBSD$

PORTNAME=	pinta
PORTVERSION=	1.5
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/PintaProject/Pinta/releases/download/${PORTVERSION}/

MAINTAINER=	olivierw1+bugzilla-freebsd@hotmail.com
COMMENT=	Simple Gtk\# Paint Program

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license-mit.txt

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:devel/mono-addins \
		intltool-update:textproc/intltool
RUN_DEPENDS=	mono-addins>0:devel/mono-addins

USES=		desktop-file-utils gmake gnome mono pkgconfig gettext-tools:build
USE_GNOME=	gtksharp20

GNU_CONFIGURE=		yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls

INSTALLS_ICONS=	yes

.include <bsd.port.mk>
