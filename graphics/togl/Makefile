PORTNAME=	togl
DISTVERSION=	2.0
DISTVERSIONSUFFIX=	-src
PORTREVISION=	2
CATEGORIES=	graphics tk
MASTER_SITES=	SF/${PORTNAME}/Togl/${PORTVERSION}
DISTNAME=	Togl${DISTVERSIONFULL}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk OpenGL widget
WWW=		http://togl.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gl gmake tk:86,tea xorg
USE_GL=		gl
USE_LDCONFIG=	${PREFIX}/lib/Togl2.0
USE_XORG=	x11 xt xmu

WRKSRC=		${WRKDIR}/Togl2.0

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

TOGL_INSTDIR=	${PREFIX}/lib/${DISTNAME}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|wish |${WISH:T} |' ${WRKSRC}/*.tcl
	@${REINPLACE_CMD} -e 's/FreeBSD-\*/FreeBSD-*|DragonFly-*/g' \
		${WRKSRC}/configure

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

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
