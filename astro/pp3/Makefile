# Created by: ijliao
# $FreeBSD$

PORTNAME=	pp3
PORTVERSION=	1.3.3
PORTREVISION=	6
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/PP3/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates celestial charts

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

USE_BZIP2=	yes

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} \
		&& ${CXX} ${CXXFLAGS} -DPP3DATA=\"${DATADIR}\" pp3.cc -o pp3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pp3 ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.dat ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
