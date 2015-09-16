# Created by: maho@FreeBSD.org
# $FreeBSD$

PORTNAME=	megapov
PORTVERSION=	1.2.1
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://megapov.inetart.net/packages/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unofficial extensions of POV-Ray

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff
#RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray-meta

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALL_WRKSRC=	${WRKSRC}/unix

USES=		gmake jpeg tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	COMPILED_BY="ports@FreeBSD.org"

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/megapov

OPTIONS_DEFINE=		DOCS EXAMPLES OPTIMIZED_CFLAGS X11
OPTIONS_DEFINE_amd64=	SVGALIB
OPTIONS_DEFINE_i386=	SVGALIB

OPTIMIZED_CFLAGS_CFLAGS=\
			-O3 -ffast-math -finline-functions \
			-fomit-frame-pointer -funroll-loops \
			-fexpensive-optimizations
SVGALIB_LIB_DEPENDS=	libvga.so:${PORTSDIR}/graphics/svgalib
SVGALIB_CONFIGURE_WITH=	svga
X11_USE=		xorg=x11,xpm
X11_CONFIGURE_WITH=	x

post-patch:
	@${REINPLACE_CMD} -e \
		's|"-O3"|""|' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in include scenes
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>
