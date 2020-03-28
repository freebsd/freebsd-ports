# $FreeBSD$

PORTNAME=	go-for-it
DISTVERSION=	1.7.3
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stylish to-do list with built-in productivity timer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libnotify.so:devel/libnotify

USES=		cmake gnome gettext pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	JMoerman
GH_PROJECT=	Go-For-It
USE_GNOME=	cairo glib20 gtk30 intltool

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
