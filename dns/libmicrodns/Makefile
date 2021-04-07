PORTNAME=	libmicrodns
DISTVERSION=	0.2.0
CATEGORIES=	dns
MASTER_SITES=	https://github.com/videolabs/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	microdns-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	mDNS library focused on being simple and cross-platform

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 meson tar:xz
USE_LDCONFIG=	yes

MESON_ARGS=	-Dexamples=disabled

PLIST_FILES=	include/microdns/microdns.h \
		include/microdns/rr.h \
		lib/libmicrodns.so \
		lib/libmicrodns.so.1 \
		lib/libmicrodns.so.1.0.0 \
		libdata/pkgconfig/microdns.pc

.include <bsd.port.mk>
