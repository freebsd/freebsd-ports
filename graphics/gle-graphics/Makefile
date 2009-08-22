# New ports collection makefile for:	glx
# Date created:		2006-11-10
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	gle-graphics
PORTVERSION=	4.0.12
PORTREVISION=	3
CATEGORIES=	graphics print
MASTER_SITES=	SF/glx/gle4%20%28Current%20Active%20Version%29/${PORTVERSION}
DISTNAME=	GLE-${PORTVERSION}-src

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A graphics language that produces images from script files

RUN_DEPENDS=	gv:${PORTSDIR}/print/gv

OPTIONS=	BITMAP_IMAGES "Support for including bitmap images" On \
		LATEX_GS "Use LaTeX & GhostScript" On \
		X_WINDOWS "Use X Windows System" On

WRKSRC=	${WRKDIR}/gle4

GNU_CONFIGURE=	yes
# GUI requires QT 4.1.X
CONFIGURE_ARGS+=	--with-qt=no

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
REINPLACE_FILES=	configure

USE_GMAKE=	yes
USE_ZIP=	yes

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${REINPLACE_FILES}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_BITMAP_IMAGES)
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiffxx.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	 --with-jpeg=${LOCALBASE} --with-tiff=${LOCALBASE} --with-png=${LOCALBASE}
.else
CONFIGURE_ARGS+=	 --with-jpeg=no --with-png=no -with-tiff=no
.endif

.if !defined(WITHOUT_LATEX_GS)
USE_GHOSTSCRIPT_RUN=	yes
RUN_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
.endif

.if !defined(WITHOUT_X_WINDOWS)
CONFIGURE_ARGS+=	--with-x
USE_XORG=	x11
.endif

.include <bsd.port.post.mk>
