# New ports collection makefile for: Sun fortran preprocessor fpp	
# Date created:		30 January 1996
# Whom:		 	vazquez@iqm.unicamp.br	
#
# $FreeBSD$
#

PORTNAME=	fpp
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netlib.org/fortran/
DISTNAME=	fdfpp
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fortran preprocessor for FORTRAN 77 and Fortran 90 programs

USE_GMAKE=	yes
ALL_TARGET=	bsd44
INSTALL_TARGET=	bsd44-install
MAN1=		fpp.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/fpp
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/fpp
	${INSTALL_MAN} ${WRKSRC}/fpp_spec ${PREFIX}/share/doc/fpp
	${INSTALL_MAN} ${WRKSRC}/fpp_license.ps ${PREFIX}/share/doc/fpp
.endif

.include <bsd.port.mk>
