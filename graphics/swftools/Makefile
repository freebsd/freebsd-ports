# ex:ts=8
# Ports collection makefile for:	swftools
# Date created:			Feb 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swftools
PORTVERSION=	0.4.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.quiss.org/swftools/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	SWF manipulation and generation utilities

LIB_DEPENDS=	t1.4:${PORTSDIR}/devel/t1lib \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=	jpeg2swf.1 pdf2swf.1 png2swf.1 swfcombine.1 swfdump.1 swfextract.1 \
	swfstrings.1 wav2swf.1

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g ; \
		 s|^CXXFLAGS=|#CXXFLAGS=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
