# Created by: Ka Ho Ng <khng300@gmail.com>
# $FreeBSD$

PORTNAME=	ibus-rime
DISTVERSION=	1.4.0-14
CATEGORIES=	chinese

MAINTAINER=	khng300@gmail.com
COMMENT=	IBus engine for Rime users

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zh-rime-data>=g0:chinese/rime-data
LIB_DEPENDS=	libibus-1.0.so:textproc/ibus \
		libnotify.so:devel/libnotify \
		librime.so:chinese/librime
RUN_DEPENDS=	zh-rime-data>=g0:chinese/rime-data

USES=		cmake gnome pkgconfig
USE_CSTD=	c99

INSTALLS_ICONS=		yes

USE_GITHUB=	yes
GH_ACCOUNT=	rime
GH_TAGNAME=	bfabe67

.include <bsd.port.mk>
