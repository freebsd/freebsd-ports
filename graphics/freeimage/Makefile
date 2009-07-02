# New ports collection makefile for:	freeimage
# Date created:		2005-09-01
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	freeimage
PORTVERSION=	3.12.0
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	FreeImage${PORTVERSION:S/.//g}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An open source graphics library

WRKSRC=		${WRKDIR}/FreeImage
USE_GMAKE=	yes
USE_ZIP=	yes
# convert CRLF to LF for gcc-2.95
EXTRACT_BEFORE_ARGS=	-qoa
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

PLIST_FILES=	include/FreeImage.h \
		lib/libfreeimage.a \
		lib/libfreeimage-3.12.0.so \
		lib/libfreeimage.so.3

post-patch:
	${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g'
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g; s|-g root|-g wheel|g' ${WRKSRC}/Makefile.gnu

post-install:
	${LN} -f ${PREFIX}/lib/libfreeimage-3.12.0.so ${PREFIX}/lib/libfreeimage.so.3

.include <bsd.port.post.mk>
