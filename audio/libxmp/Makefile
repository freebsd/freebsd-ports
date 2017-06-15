# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxmp
PORTVERSION=	4.4.1
CATEGORIES=	audio
MASTER_SITES=	SF/xmp/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module rendering library for xmp

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/docs/COPYING.LIB

USES=		gmake pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	include/xmp.h lib/libxmp.so lib/libxmp.so.4 \
		lib/libxmp.so.${PORTVERSION} libdata/pkgconfig/libxmp.pc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxmp.so.${PORTVERSION}

.include <bsd.port.mk>
