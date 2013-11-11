# Created by: Randall Hopper <aa8vb@ipass.net>
# $FreeBSD$

PORTNAME=	togl
PORTVERSION=	1.7
PORTREVISION=	4
CATEGORIES=	graphics tk
MASTER_SITES=	SF/${PORTNAME}/Togl/${PORTVERSION}
DISTNAME=	Togl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk OpenGL widget

USES+=		gmake tk
USE_XORG=	x11 xt xmu
USE_GL=		gl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tk=${TK_LIBDIR} \
		--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}
USE_LDCONFIG=	yes

TOGL_INSTDIR=	${PREFIX}/lib/${DISTNAME}

CPPFLAGS+=	-I${TK_INCLUDEDIR}
LDFLAGS+=	-L${TK_LIBDIR}

PLIST_SUB+=	TK_VER=${TK_VER}

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|wish |${WISH:T} |' ${WRKSRC}/*.tcl

do-install:
	@${MKDIR} ${TOGL_INSTDIR}
.for i in togl.h togl_ws.h libTogl1.7.so pkgIndex.tcl
	${INSTALL_DATA} ${WRKSRC}/${i} ${TOGL_INSTDIR}
.endfor
	${LN} -s ${TOGL_INSTDIR}/libTogl1.7.so  ${TOGL_INSTDIR}/libtogl.so.1
	${LN} -s ${TOGL_INSTDIR}/libTogl1.7.so  ${PREFIX}/lib/libtogl.so
	${LN} -s ${TOGL_INSTDIR}/libTogl1.7.so  ${PREFIX}/lib/libtogl.so.1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Togl.html ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Makefile ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ben.rgb ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/double.c ${WRKSRC}/double.tcl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gears.c ${WRKSRC}/gears.tcl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/image.c ${WRKSRC}/image.h ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/index.c ${WRKSRC}/index.tcl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/overlay.c ${WRKSRC}/overlay.tcl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/stereo.c ${WRKSRC}/stereo.tcl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/texture.c ${WRKSRC}/texture.tcl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/togl.c ${WRKSRC}/togl.h ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tree2.rgba ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
