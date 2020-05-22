# $FreeBSD$

PORTNAME=	tllist
DISTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	https://codeberg.org/dnkl/tllist/archive/
DISTNAME=	${DISTVERSION}

MAINTAINER=	ports@xanderio.de
COMMENT=	C header file only implementation of a typed linked list

LICENSE=	MIT

USES=		meson
USE_CSTD=	c99

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	include/tllist.h \
		libdata/pkgconfig/tllist.pc

.include <bsd.port.mk>
