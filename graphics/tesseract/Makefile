# New ports collection makefile for:	tesseract
# Date created:		18 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tesseract
DISTVERSION=	1.04b
CATEGORIES=	graphics
MASTER_SITES=	http://tesseract-ocr.googlecode.com/files/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Commercial quality open source OCR engine

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBTIFF_CFLAGS="-I${LOCALBASE}/include"\
		LIBTIFF_LIBS="-L${LOCALBASE}/lib -ltiff"
WRKSRC=	${WRKDIR}/${DISTNAME:S/b$//}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/X11/xterm|${LOCALBASE}/bin/xterm|'\
		${WRKSRC}/ccutil/debugwin.cpp

# fuzplist: cntraining mftraining tessdata

.include <bsd.port.mk>
