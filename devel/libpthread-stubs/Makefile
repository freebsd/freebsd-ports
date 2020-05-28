# Created by: wahjava
# $FreeBSD$

PORTNAME=	libpthread-stubs
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	https://xcb.freedesktop.org/dist/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Weak aliases for pthread functions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix tar:bzip2
GNU_CONFIGURE=	yes
NO_ARCH=	yes

PLIST_FILES=	libdata/pkgconfig/pthread-stubs.pc

.include <bsd.port.mk>
