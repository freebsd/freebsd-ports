# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	gle-graphics
PORTVERSION=	4.0.12
PORTREVISION=	7
CATEGORIES=	graphics print
MASTER_SITES=	SF/glx/gle4%20%28Current%20Active%20Version%29/${PORTVERSION}
DISTNAME=	GLE-${PORTVERSION}-src

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A graphics language that produces images from script files

RUN_DEPENDS=	gv:${PORTSDIR}/print/gv

OPTIONS_DEFINE=	BITMAP_IMAGES LATEX_GS X11
OPTIONS_DEFAULT=	BITMAP_IMAGES LATEX_GS X11
BITMAP_IMAGES_DESC=	Support for including bitmap images
LATEX_GS_DESC=		Use LaTeX & GhostScript

WRKSRC=	${WRKDIR}/gle4

GNU_CONFIGURE=	yes
# GUI requires QT 4.1.X
CONFIGURE_ARGS+=	--with-qt=no

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
REINPLACE_FILES=	configure

USES=		gmake zip

NO_STAGE=	yes
post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${REINPLACE_FILES}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBITMAP_IMAGES}
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiffxx.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	 --with-jpeg=${LOCALBASE} --with-tiff=${LOCALBASE} --with-png=${LOCALBASE}
.else
CONFIGURE_ARGS+=	 --with-jpeg=no --with-png=no -with-tiff=no
.endif

.if ${PORT_OPTIONS:MLATEX_GS}
USE_GHOSTSCRIPT_RUN=	yes
USE_TEX=	latex
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--with-x
USE_XORG=	x11
.endif

.include <bsd.port.mk>
