# New ports collection makefile for:	ohugs
# Date created:				03.03.03
# Whom:					Steffen Mazanek <steffen.mazanek@unibw-muenchen.de>
# $FreeBSD$
#

PORTNAME=	ohugs
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.math.chalmers.se/~nordland/ohugs/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	steffen.mazanek@unibw-muenchen.de
COMMENT=	Interpreter for Haskell with object-oriented features

.if !defined(WITHOUT_X11)
LIB_DEPENDS=	tix4184:${PORTSDIR}/x11-toolkits/tix
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/.src//}
USE_REINPLACE=	yes
USE_BISON=	yes

post-patch:
.if defined(WITHOUT_X11)
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/extra-patch-src::prelude.h
.endif
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/Makefile
.if !defined(WITHOUT_X11)
	@${REINPLACE_CMD} -e 's|#CFLAGS+=|CFLAGS+= -I${PREFIX}/include/tk8.2 \
	 -I${PREFIX}/include/tcl8.2 -I${PREFIX}/include -I${X11BASE}/include| ; \
	 s|#LDFLAGS+=|LDFLAGS+=-L${PREFIX}/lib -ltk82 -ltcl82 -ltix4184|' \
		${WRKSRC}/src/Makefile
.endif

.include <bsd.port.mk>
