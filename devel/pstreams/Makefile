# Created by: Andrew Wingorodov <mail@andr.ru>
# $FreeBSD$

PORTNAME=	pstreams
PORTVERSION=	0.8.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Release%200.8.x

MAINTAINER=	eg@fbsd.lt
COMMENT=	C++ utility for simple IOStream-based IPC

LICENSE=	LGPL3

USES=		gmake
MAKE_ENV+=	INSTALL_PREFIX=${PREFIX}
NO_BUILD=	yes

PLIST_FILES=	include/pstreams/pstream.h
PLIST_DIRS=	include/pstreams

.include <bsd.port.mk>
