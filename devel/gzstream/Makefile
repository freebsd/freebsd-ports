# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gzstream
DISTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	CENKES \
		http://www.skysmurf.nl/comp/FreeBSD/distfiles/

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	Provides zlib functionality in an iostream

LICENSE=	LGPL21

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	lib/lib${PORTNAME}.so lib/lib${PORTNAME}.so.0 \
		include/${PORTNAME}.h
ALL_TARGET=	default
CFLAGS+=	-fPIC -I.

post-patch:
	@${REINPLACE_CMD} -e 's/=/?=/;s/\.a/.so/g;s/CPPFL/CXXFL/g;\
		s/{AR}/{CC} $${CFLAGS} -lz -shared -o/' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib/
	${LN} -sf lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.0
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
