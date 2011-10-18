# ex:ts=8
# Ports collection makefile for:	pp3
# Date created:			Dec 24, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pp3
PORTVERSION=	1.3.3
PORTREVISION=	5
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/PP3/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates celestial charts

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

USE_BZIP2=	yes

do-build:
	cd ${WRKSRC} \
		&& ${CXX} ${CXXFLAGS} -DPP3DATA=\"${DATADIR}\" pp3.cc -o pp3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pp3 ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.dat ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
