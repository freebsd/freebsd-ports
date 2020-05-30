# $FreeBSD$

PORTNAME=	libinstpatch
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.5
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Instrument file software library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		cmake gettext-runtime gnome localbase:ldflags pkgconfig tar:bz2
USE_GITHUB=	yes
GH_ACCOUNT=	swami
USE_GNOME=	glib20
USE_LDCONFIG=	yes

CMAKE_OFF=	INTROSPECTION_ENABLED

PLIST_SUB=	VER=2

.include <bsd.port.mk>
