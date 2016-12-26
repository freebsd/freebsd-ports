# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gzstream
DISTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.skysmurf.nl/comp/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides zlib functionality in an iostream

LICENSE=	LGPL21

BROKEN=		unfetchable (apparently abandoned upstream)

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	lib/lib${PORTNAME}.so lib/lib${PORTNAME}.so.0 \
		include/${PORTNAME}.h
ALL_TARGET=	default
CFLAGS+=	-fPIC -I.

post-patch:
	@${REINPLACE_CMD} -e 's/=/?=/;s/\.a/.so/g;s/CPPFL/CXXFL/g;\
		s/{AR}/{CC} $${CFLAGS} -lz -shared -Wl,-soname=lib${PORTNAME}.so.0 -o/' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.0
	${LN} -sf lib${PORTNAME}.so.0 ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
