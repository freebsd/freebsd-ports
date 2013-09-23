# Created by: Steven Wallace <swallace@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpaint
PORTVERSION=	2.9.9.4
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/sf-${PORTNAME}/sf-${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Simple paint program

LICENSE=	GPLv3

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libopenjpeg.so:${PORTSDIR}/graphics/openjpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjbig.so:${PORTSDIR}/graphics/jbigkit \
		libXaw3dxft.so:${PORTSDIR}/x11-toolkits/libxaw3dxft
RUN_DEPENDS=	psselect:${PORTSDIR}/print/psutils

USE_BZIP2=	yes
USE_XORG=	xft xmu xpm
USE_AUTOTOOLS=	libtool
USE_GHOSTSCRIPT_RUN=yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	RM="${RM} -f"

MAN1=		xpaint.1 pdfconcat.1 imgmerge.1

NO_STAGE=	yes
post-extract:
	@${RM} -f ${WRKSRC}/XPaint.ad

post-patch:
	@${REINPLACE_CMD} -e 's/-ldl //' \
		${WRKSRC}/configure ${WRKSRC}/rw/configure
	@${REINPLACE_CMD} -e '/^LIBTOOL/d' \
		-e '/^install-exec-am:/s/install-libLTLIBRARIES//' \
		${WRKSRC}/rw/Makefile.in
	@${REINPLACE_CMD} -e '/if (!image)/s/return;/return -1;/' \
		${WRKSRC}/rw/readWriteTGA.c

.include <bsd.port.mk>
