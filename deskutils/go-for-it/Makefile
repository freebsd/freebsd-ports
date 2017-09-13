# $FreeBSD$

PORTNAME=	go-for-it
PORTVERSION=	1.5
DISTVERSIONPREFIX=	release_v
CATEGORIES=	deskutils

MAINTAINER=	neel@neelc.org
COMMENT=	Stylish to-do list with built-in productivity timer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libnotify.so:devel/libnotify

USES=		cmake gettext pkgconfig
USE_GNOME=	cairo glib20 gtk30
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mank319
GH_PROJECT=	Go-For-It

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/go-for-it.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
