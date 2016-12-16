# $FreeBSD$

PORTNAME=	go-for-it
PORTVERSION=	1.4.7
DISTVERSIONPREFIX=	release_
CATEGORIES=	deskutils

MAINTAINER=	neel@neelc.org
COMMENT=	Stylish to-do list with built-in productivity timer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libnotify.so:devel/libnotify

USE_GITHUB=	yes
GH_ACCOUNT=	mank319
GH_PROJECT=	Go-For-It

GNU_CONFIGURE=	yes
USES=		cmake gettext-runtime pkgconfig
USE_GNOME=	cairo glib20 gtk30
INSTALLS_ICONS=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/go-for-it.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
