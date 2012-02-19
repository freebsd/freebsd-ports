# New ports collection makefile for:	xpaint
# Date created:		2 Jan 1995
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	xpaint
PORTVERSION=	2.9.9
CATEGORIES=	graphics
MASTER_SITES=	SF/sf-${PORTNAME}/sf-${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A simple paint program

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		openjpeg:${PORTSDIR}/graphics/openjpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2 \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		Xaw3dxft.7:${PORTSDIR}/x11-toolkits/libxaw3dxft

USE_BZIP2=	yes
USE_XORG=	xft xmu xpm
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	RM="${RM} -f"

MAN1=		xpaint.1 pdfconcat.1 imgmerge.1

post-extract:
	@${LN} -sf ${LOCALBASE}/include/X11/Xaw3dxft ${WRKSRC}/xaw_incdir
	@${RM} -f ${WRKSRC}/XPaint.ad

post-patch:
	@${REINPLACE_CMD} -e 's/-ldl //' \
		${WRKSRC}/configure ${WRKSRC}/rw/configure
	@${REINPLACE_CMD} -Ee 's:/etc(/X11/app-defaults):${PREFIX}/lib\1:' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/if (!image)/s/return;/return -1;/' \
		${WRKSRC}/rw/readWriteTGA.c

.include <bsd.port.mk>
