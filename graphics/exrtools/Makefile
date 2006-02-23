# New ports collection makefile for:	exrtools
# Date created:				15 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	exrtools
PORTVERSION=	0.4
CATEGORIES=	graphics
MASTER_SITES=	http://scanline.ca/exrtools/ \
		http://critical.ch/distfiles/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utilities for manipulating with HDR images in OpenEXR format

LIB_DEPENDS=	Half:${PORTSDIR}/graphics/OpenEXR \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/exrblur bin/exrchr bin/exricamtm bin/exrnlm \
		bin/exrnormalize bin/exrpptm bin/exrstats \
		bin/exrtopng bin/jpegtoexr bin/pngtoexr bin/ppmtoexr

MAN1=		exrblur.1 exrchr.1 exricamtm.1 exrnlm.1 exrnormalize.1 \
		exrpptm.1 exrstats.1 exrtools.1 exrtopng.1 jpegtoexr.1 \
		pngtoexr.1 ppmtoexr.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|<values\.h>|<float.h>|' \
		${WRKSRC}/src/exrnormalize.c \
		${WRKSRC}/src/exrpptm.c \
		${WRKSRC}/src/exrstats.c
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint\.h|inttypes.h|' \
		${WRKSRC}/src/exrblur.c \
		${WRKSRC}/src/exrchr.c \
		${WRKSRC}/src/exrnlm.c \
		${WRKSRC}/src/exrnormalize.c \
		${WRKSRC}/src/exrpptm.c \
		${WRKSRC}/src/ppmtoexr.c \
		${WRKSRC}/src/exricamtm.c \
		${WRKSRC}/src/jpeginput.h \
		${WRKSRC}/src/pngoutput.h \
		${WRKSRC}/src/pnginput.h
	@${REINPLACE_CMD} -e 's|inttypes\.h|sys/types.h|' \
		${WRKSRC}/src/ppmtoexr.c
.endif

.include <bsd.port.post.mk>
