# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deadbeef-mpris2-plugin
PORTVERSION=	1.12
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	MPRIS protocol version 2 plugin for DeaDBeeF music player

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/deadbeef/deadbeef.h:audio/deadbeef
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	Serranya

USES=		autoreconf gnome libtool pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	lib/deadbeef/mpris.so

.include <bsd.port.mk>
