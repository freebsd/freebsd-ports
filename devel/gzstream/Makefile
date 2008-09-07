# New ports collection makefile for:	gzstream
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gzstream
DISTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	CENKES
# http://www.cs.unc.edu/Research/compgeom/gzstream/gzstream.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides zlib functionality in an iostream

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
	@${INSTALL_PROGRAM} ${WRKSRC}/lib${PORTNAME}.so ${PREFIX}/lib/
	@${LN} -sf lib${PORTNAME}.so ${PREFIX}/lib/lib${PORTNAME}.so.0
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${PREFIX}/include/

.include <bsd.port.mk>
