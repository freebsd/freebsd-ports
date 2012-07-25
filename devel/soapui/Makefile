# New ports collection Makefile for:		soapui
# Date created:					2007-07-25
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	soapui
PORTVERSION=	4.5.1
CATEGORIES=	devel java www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/4.5.1/
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux-bin

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	A web service, SOA, and SOAP testing tool

USE_ZIP=	YES
USE_JAVA=	1.5+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
REINPLACE_ARGS=	-i ''
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-build:
	${REINPLACE_CMD} -e 's:%%SOAPUI_HOME%%:${DATADIR}:' \
			-e 's:%%JAVA%%:${JAVA}:' ${WRKSRC}/bin/${PORTNAME}.sh

.include <bsd.port.options.mk>

do-install:
.for dir in bin lib
	( cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${DATADIR}/${dir} )
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}.sh ${PREFIX}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
	( cd ${WRKSRC}/Tutorials && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/Tutorials )
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.	for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.	endfor
	( cd ${WRKSRC}/licenses && ${COPYTREE_SHARE} . ${DOCSDIR}/licenses )
.endif

.include <bsd.port.mk>
