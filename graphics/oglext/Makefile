# New ports collection makefile for: oglext
# Date created:		01 Feb 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	oglext
PORTVERSION=	1.0.2
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.julius.caesar.de/oglext/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	A library for easier access to OpenGL extensions

USE_ZIP=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	${WRKSRC}/build/linux-gcc/Makefile
MAKE_ENV=	AR="${AR}" LN="${LN}" RM="${RM}"

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e "s/`${PRINTF} '\r'`//"

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/libOglExt.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libOglExt.so.1 ${PREFIX}/lib/libOglExt.so
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/libOglExt.a ${PREFIX}/lib
# install includes in separate dir to avoid conflicts with Mesa
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/${PORTNAME}
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
