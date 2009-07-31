# New ports collection makefile for:	exrtools
# Date created:				15 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	exrtools
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://scanline.ca/exrtools/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utilities for manipulating with HDR images in OpenEXR format

LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/exrblur bin/exrchr bin/exricamtm bin/exrnlm \
		bin/exrnormalize bin/exrpptm bin/exrstats \
		bin/exrtopng bin/jpegtoexr bin/pngtoexr bin/ppmtoexr

MAN1=		exrblur.1 exrchr.1 exricamtm.1 exrnlm.1 exrnormalize.1 \
		exrpptm.1 exrstats.1 exrtools.1 exrtopng.1 jpegtoexr.1 \
		pngtoexr.1 ppmtoexr.1

post-patch:
	@${REINPLACE_CMD} -e 's|<values\.h>|<float.h>|' \
		${WRKSRC}/src/exrnormalize.c \
		${WRKSRC}/src/exrpptm.c \
		${WRKSRC}/src/exrstats.c

.include <bsd.port.mk>
