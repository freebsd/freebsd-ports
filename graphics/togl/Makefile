# New ports collection makefile for:	Togl
# Date created:		Wed Aug 18 18:49:17 EDT 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

PORTNAME=	togl
PORTVERSION=	1.7
PORTREVISION=	4
CATEGORIES=	graphics tk
MASTER_SITES=	SF/${PORTNAME}/Togl/${PORTVERSION}
DISTNAME=	Togl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tk OpenGL widget

USE_XORG=	x11 xt xmu
USE_GL=		gl
USE_TCL_BUILD=	84+
USE_TCL=	84+
USE_TK_BUILD=	84+
USE_TK=		84+
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tk=${TK_LIBDIR} \
		--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
USE_LDCONFIG=	yes

TOGL_INSTDIR=	${PREFIX}/lib/tk${TK_VER}/${DISTNAME}
PLIST_SUB=	TOGL_INSTDIR="${TOGL_INSTDIR:S,^${PREFIX}/,,}"

CPPFLAGS+=	-I${TK_INCLUDEDIR}
LDFLAGS+=	-L${TK_LIBDIR}

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Togl.html ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
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
