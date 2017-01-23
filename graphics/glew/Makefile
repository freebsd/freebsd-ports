# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	glew
PORTVERSION=	1.13.0
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The OpenGL Extension Wrangler Library

LICENSE=	MIT BSD3CLAUSE
LICENSE_COMB=	dual

USES=		gmake tar:tgz
USE_XORG=	x11 xext xi xmu
USE_GL=		yes
USE_LDCONFIG=	yes

MAKE_ENV+=	GLEW_DEST=${PREFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS +=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/glewinfo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/visualinfo ${STAGEDIR}${PREFIX}/bin

	${INSTALL_PROGRAM} ${WRKSRC}/lib/libGLEW.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libGLEW.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libGLEWmx.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libGLEWmx.so.1
	${LN} -sf ${PREFIX}/lib/libGLEW.so.1 ${STAGEDIR}${PREFIX}/lib/libGLEW.so
	${LN} -sf ${PREFIX}/lib/libGLEWmx.so.1 ${STAGEDIR}${PREFIX}/lib/libGLEWmx.so
	${INSTALL_DATA} ${WRKSRC}/lib/libGLEW.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libGLEWmx.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/*.h ${STAGEDIR}${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/glew.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/glewmx.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in css html jpg png
	${INSTALL_DATA} ${WRKSRC}/doc/*.${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
