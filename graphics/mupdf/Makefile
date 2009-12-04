# New ports collection makefile for:	mupdf
# Date created:		2009-08-07
# Whom:			Martin Dieringer <martin.dieringer@gmx.de>
#
# $FreeBSD$

PORTNAME=	mupdf
DISTVERSION=	2009-07-07
CATEGORIES=	graphics
MASTER_SITES=	http://ccxvii.net/mupdf/download/
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Lightweight PDF viewer and toolkit

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.10:${PORTSDIR}/graphics/jpeg

USE_XORG=	x11 xext
JAM_ARGS=	-q -sLOCALBASE=${LOCALBASE} \
		-sPTHREAD_LIBS=${PTHREAD_LIBS} ${_MAKE_JOBS}
MAKE_JOBS_SAFE=	yes

EXECUTABLES=	cmapdump    pdfdraw     pdfinfo \
		fontdump    pdfclean    pdfextract  pdfshow

OPTIONS=	CJK "Enable Asian Fontset" On

.include <bsd.port.options.mk>

.if defined(WITHOUT_CJK)
JAM_ARGS+=	-sDEFINES=NOCJK
.endif

do-build:
	cd ${WRKSRC} &&	jam ${JAM_ARGS}

do-install:
	${INSTALL} ${WRKSRC}/build/mupdf ${PREFIX}/bin/mupdf
.for f in ${EXECUTABLES}
	${INSTALL} ${WRKSRC}/build/$f ${PREFIX}/bin/mu_$f ;
.endfor

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64
.endif

.include <bsd.port.post.mk>
