# New ports collection makefile for:	epstool
# Date created:		23 October 1999
# Whom:			Yuzo FURUKAWA <hurukawa@kuee.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	epstool
PORTVERSION=	2.10
CATEGORIES=	graphics
MASTER_SITES=	ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/ghostgum/
DISTNAME=	gsv42src

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
MAKEFILE=	makefile.unx

post-extract:
.for file in epstool.zip src.zip
	@cd ${WRKDIR} && unzip -q -aa ${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/epstool.htm ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../gsview.css ${DOCSDIR}
.endif

.include <bsd.port.mk>
