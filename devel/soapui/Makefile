# New ports collection Makefile for:		soapui
# Date created:					2007-07-25
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	soapui
PORTVERSION=	3.5
CATEGORIES=	devel java www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux-bin

MAINTAINER=	niels@FreeBSD.org
COMMENT=	A web service, SOA and SOAP testing tool

USE_ZIP=	YES
USE_JAVA=	1.5+
PORTDOCS=	LICENSE.txt readme.txt
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
REINPLACE_ARGS=	-i ''
SOAPUI_HOME=	${JAVASHAREDIR}/${PORTNAME}

do-build:
	${REINPLACE_CMD} -e 's:%%SOAPUI_HOME%%:${SOAPUI_HOME}:' \
			-e 's:%%JAVA%%:${JAVA}:' ${WRKSRC}/bin/${PORTNAME}.sh
do-install:
.for dir in bin lib
	( cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${SOAPUI_HOME}/${dir} )
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}.sh ${PREFIX}/bin
.if	!defined(NOPORTEXAMPLES)
	( cd ${WRKSRC}/Tutorials && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/Tutorials )
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.	for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.	endfor
	( cd ${WRKSRC}/licenses && ${COPYTREE_SHARE} . ${DOCSDIR}/licenses )
.endif

.include <bsd.port.mk>
