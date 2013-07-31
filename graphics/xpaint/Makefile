# Created by: Steven Wallace <swallace@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpaint
PORTVERSION=	2.9.9.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/sf-${PORTNAME}/sf-${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Simple paint program

LICENSE=	GPLv3

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		openjpeg:${PORTSDIR}/graphics/openjpeg \
		tiff:${PORTSDIR}/graphics/tiff \
		freetype:${PORTSDIR}/print/freetype2 \
		jbig:${PORTSDIR}/graphics/jbigkit \
		Xaw3dxft:${PORTSDIR}/x11-toolkits/libxaw3dxft
RUN_DEPENDS=	psselect:${PORTSDIR}/print/psutils

USE_BZIP2=	yes
USE_XORG=	xft xmu xpm
USE_AUTOTOOLS=	libtool
USE_GHOSTSCRIPT_RUN=yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	RM="${RM} -f"

MAN1=		xpaint.1 pdfconcat.1 imgmerge.1

post-extract:
	@${RM} -f ${WRKSRC}/XPaint.ad

post-patch:
	@${REINPLACE_CMD} -e 's/-ldl //' \
		${WRKSRC}/configure ${WRKSRC}/rw/configure
	@${REINPLACE_CMD} -Ee 's:/etc(/X11/app-defaults):${PREFIX}/lib\1:' \
		-e '/xaw_incdir/s,/usr/include,${LOCALBASE}/include,' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^LIBTOOL/d' \
		-e '/^install-exec-am:/s/install-libLTLIBRARIES//' \
		${WRKSRC}/rw/Makefile.in
	@${REINPLACE_CMD} -e '/if (!image)/s/return;/return -1;/' \
		${WRKSRC}/rw/readWriteTGA.c

.include <bsd.port.mk>
