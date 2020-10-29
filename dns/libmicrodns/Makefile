# $FreeBSD$

PORTNAME=	libmicrodns
DISTVERSION=	0.2.0
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DNS library focused on being simple and cross-platform

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	videolabs

PLIST_FILES=	include/microdns/microdns.h \
		include/microdns/rr.h \
		lib/libmicrodns.so \
		lib/libmicrodns.so.1 \
		lib/libmicrodns.so.1.0.0 \
		libdata/pkgconfig/microdns.pc

.include <bsd.port.mk>
