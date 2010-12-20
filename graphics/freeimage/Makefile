# New ports collection makefile for:	FreeImage
# Date created:				2005-09-01
# Whom:					Choe, Cheng-Dae <whitekid@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	freeimage
PORTVERSION=	3.14.1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Source%20Distribution/${PORTVERSION}
DISTNAME=	FreeImage${PORTVERSION:S/.//g}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An open source graphics library

USE_ZIP=	yes
USE_DOS2UNIX=	Source/LibOpenJPEG/opj_malloc.h
USE_GMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/FreeImage

PLIST_FILES=	include/FreeImage.h \
		lib/libfreeimage.a \
		lib/libfreeimage-${PORTVERSION}.so \
		lib/libfreeimage.so.3 \
		lib/libfreeimage.so

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}| ; s|-g root|-g wheel|' \
		${WRKSRC}/Makefile.gnu

.include <bsd.port.post.mk>
