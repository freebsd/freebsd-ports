# New ports collection makefile for:	epstool
# Date created:		23 October 1999
# Whom:			Yuzo FURUKAWA <hurukawa@kuee.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	epstool
PORTVERSION=	1.80
CATEGORIES=	graphics
MASTER_SITES=	ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/ghostgum/
DISTNAME=	gsv40src

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
	@${MKDIR} ${PREFIX}/share/doc/epstool
	${INSTALL_DATA} ${WRKSRC}/epstool.htm ${PREFIX}/share/doc/epstool
.endif

.include <bsd.port.mk>
