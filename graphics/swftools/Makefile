# ex:ts=8
# Ports collection makefile for:	swftools
# Date created:			Feb 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swftools
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.quiss.org/swftools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SWF manipulation and generation utilities

LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGSS="-L${LOCALBASE}/lib"

MAN1=	font2swf.1 jpeg2swf.1 pdf2swf.1 png2swf.1 swfcombine.1 swfdump.1 \
	swfextract.1 swfstrings.1 wav2swf.1

post-patch:
	@${REINPLACE_CMD} -e 's| -O | |g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|;make|;\$$\(MAKE\)|g' ${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
