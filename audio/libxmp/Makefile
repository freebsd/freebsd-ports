PORTNAME=	libxmp
PORTVERSION=	4.5.0
CATEGORIES=	audio
MASTER_SITES=	SF/xmp/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module rendering library for xmp

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/docs/COPYING.LIB

USES=		gmake pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	include/xmp.h \
		lib/libxmp.so \
		lib/libxmp.so.${PORTVERSION} \
		lib/libxmp.so.4 \
		libdata/pkgconfig/libxmp.pc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxmp.so.${PORTVERSION}

.include <bsd.port.mk>
