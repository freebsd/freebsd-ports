# ex:ts=8
# Ports collection makefile for:	pp3
# Date created:			Dec 24, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pp3
PORTVERSION=	1.3.2
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PP3 creates celestial charts

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_BZIP2=	yes

do-build:
	@cd ${WRKSRC} && \
		${CXX} ${CXXFLAGS} -DPP3DATA=\"${DATADIR}\" pp3.cc -o pp3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pp3 ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.dat ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/pp3.ps ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
