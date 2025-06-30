PORTNAME=	nemu
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Ncurses UI for QEMU
WWW=		https://github.com/nemuTUI/nemu

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libudev.so:devel/libudev-devd \
		libjson-c.so:devel/json-c

USES=		cmake gettext-runtime gettext-tools gnome libarchive pkgconfig \
		sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	nemuTUI

USE_GNOME=	libxml2

.include <bsd.port.mk>
