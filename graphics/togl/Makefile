# New ports collection makefile for:	Togl
# Date created:		Wed Aug 18 18:49:17 EDT 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

PORTNAME=	togl
PORTVERSION=	1.7
PORTREVISION=	3
CATEGORIES=	graphics tk
MASTER_SITES=	SF/${PORTNAME}/Togl/${PORTVERSION}
DISTNAME=	Togl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tk OpenGL widget

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84 \
		tcl84.1:${PORTSDIR}/lang/tcl84

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GL=		yes
USE_XORG=	x11 xt xmu
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include/tk8.4" \
		LDFLAGS="-L${LOCALBASE}/lib/tk8.4"
CONFIGURE_ARGS=	--with-tk=${LOCALBASE}/lib/tk8.4 \
		--with-tcl=${LOCALBASE}/lib/tcl8.4 \
		--with-tclinclude=${LOCALBASE}/include/tcl8.4 \
USE_LDCONFIG=	yes

TOGL_INSTDIR=	${PREFIX}/lib/tk8.4/${DISTNAME}
PLIST_SUB=	TOGL_INSTDIR=${TOGL_INSTDIR:S,^${PREFIX}/,,}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|wish |wish8.4 |' ${WRKSRC}/*.tcl

do-install:
	@${MKDIR} ${TOGL_INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/libTogl1.7.so ${TOGL_INSTDIR}/libTogl1.7.so
	${LN} -s ${TOGL_INSTDIR}/libTogl1.7.so  ${TOGL_INSTDIR}/libtogl.so.1
	${LN} -s ${TOGL_INSTDIR}/libTogl1.7.so  ${PREFIX}/lib/libtogl.so.1
	${LN} -s ${TOGL_INSTDIR}/libTogl1.7.so  ${PREFIX}/lib/libtogl.so
	${INSTALL_DATA} ${WRKSRC}/togl.h ${WRKSRC}/togl_ws.h ${WRKSRC}/pkgIndex.tcl ${TOGL_INSTDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Makefile ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/togl.c ${WRKSRC}/togl.h ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/double.c ${WRKSRC}/double.tcl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gears.c ${WRKSRC}/gears.tcl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/index.c ${WRKSRC}/index.tcl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/overlay.c ${WRKSRC}/overlay.tcl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/stereo.c ${WRKSRC}/stereo.tcl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/texture.c ${WRKSRC}/texture.tcl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/image.c ${WRKSRC}/image.h ${WRKSRC}/ben.rgb ${WRKSRC}/tree2.rgba ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Togl.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
