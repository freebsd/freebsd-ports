# Created by: Randall Hopper <aa8vb@ipass.net>
# $FreeBSD$

PORTNAME=	togl
PORTVERSION=	1.7
PORTREVISION=	7
CATEGORIES=	graphics tk
MASTER_SITES=	SF/${PORTNAME}/Togl/${PORTVERSION}
DISTNAME=	Togl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk OpenGL widget

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gl gmake tk:tea xorg
USE_XORG=	x11 xt xmu
USE_GL=		gl
USE_LDCONFIG=	yes

TOGL_INSTDIR=	${PREFIX}/lib/${DISTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|wish |${WISH:T} |' ${WRKSRC}/*.tcl
	@${REINPLACE_CMD} -e 's/FreeBSD-\*/FreeBSD-*|DragonFly-*/g' \
		${WRKSRC}/configure

do-install:
	@${MKDIR} ${STAGEDIR}${TOGL_INSTDIR}
.for i in togl.h togl_ws.h pkgIndex.tcl
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${TOGL_INSTDIR}
.endfor
	${INSTALL_LIB} ${WRKSRC}/libTogl1.7.so ${STAGEDIR}${TOGL_INSTDIR}
	${LN} -s libTogl1.7.so  ${STAGEDIR}${TOGL_INSTDIR}/libtogl.so.1
	${LN} -s ${TOGL_INSTDIR}/libTogl1.7.so  ${STAGEDIR}${PREFIX}/lib/libtogl.so
	${LN} -s ${TOGL_INSTDIR}/libTogl1.7.so  ${STAGEDIR}${PREFIX}/lib/libtogl.so.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Togl.html ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Makefile ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ben.rgb ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/double.c ${WRKSRC}/double.tcl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gears.c ${WRKSRC}/gears.tcl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/image.c ${WRKSRC}/image.h ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/index.c ${WRKSRC}/index.tcl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/overlay.c ${WRKSRC}/overlay.tcl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/stereo.c ${WRKSRC}/stereo.tcl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/texture.c ${WRKSRC}/texture.tcl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/togl.c ${WRKSRC}/togl.h ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tree2.rgba ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
