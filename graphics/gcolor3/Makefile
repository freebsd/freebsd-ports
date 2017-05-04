# $FreeBSD$

PORTNAME=	gcolor3
PORTVERSION=	2.2
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Simple color chooser

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake gettext libtool pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Hjdskes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
