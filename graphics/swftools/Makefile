# ex:ts=8
# Ports collection makefile for:	swftools
# Date created:			Feb 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swftools
PORTVERSION=	0.6.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.quiss.org/swftools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SWF manipulation and generation utilities

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging
LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2 \
		aviplay.0:${PORTSDIR}/multimedia/avifile
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging

USE_REINPLACE=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_PYTHON=	2.2+
FREETYPE_CONFIG?=	${LOCALBASE}/bin/freetype-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGSS="-L${LOCALBASE}/lib" \
		FREETYPE_CONFIG=${FREETYPE_CONFIG}

MAN1=	avi2swf.1 font2swf.1 jpeg2swf.1 pdf2swf.1 png2swf.1 swfbbox.1 swfc.1 \
	swfcombine.1 swfdump.1 swfextract.1 swfstrings.1 wav2swf.1

post-patch:
	@${REINPLACE_CMD} -e 's| -O | |g' \
		-e 's@/usr/lib/python@${LOCALBASE}/lib/python@' \
		-e 's@/usr/include/python@${LOCALBASE}/include/python@' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|;make|;\$$\(MAKE\)|g' ${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
