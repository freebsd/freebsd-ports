# New ports collection makefile for:	epstool
# Date created:		23 October 1999
# Whom:			Yuzo FURUKAWA <hurukawa@kuee.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	epstool
PORTVERSION=	3.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/ghostgum/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create or extract preview bitmaps in EPS files

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu

USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" CDEBUG="${CFLAGS}" LINK="${CC}" EPSLIB=""
ALL_TARGET=	${PORTNAME}

post-extract:
	@${RM} -f ${WRKSRC}/epstool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/epstool ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/epstool.htm ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gsview.css ${DOCSDIR}
.endif

.include <bsd.port.mk>
