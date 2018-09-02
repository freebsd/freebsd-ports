# $FreeBSD$

PORTNAME=	gcolor3
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3
CATEGORIES=	graphics

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Simple color chooser

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: main.c: In function '_print_version_and_exit': will never be executed

USES=		gnome gettext meson libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Hjdskes
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
