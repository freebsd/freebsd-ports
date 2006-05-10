# ex:ts=8
# Ports collection makefile for:	ArgoUML
# Date created:			June 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	argouml
PORTVERSION=	0.20
CATEGORIES=	devel java
MASTER_SITES=	http://argouml-downloads.tigris.org/nonav/argouml-${PORTVERSION}/
DISTNAME=	ArgoUML-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	argomanual-${PORTVERSION}.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	phil@brassy.net
COMMENT=	A UML design tool with cognitive support

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

SUB_FILES=	argouml.sh
.if !defined(NOPORTDOCS)
PORTDOCS=	argomanual-${PORTVERSION}.pdf
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/argouml.sh ${PREFIX}/bin/argouml
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/argomanual-${PORTVERSION}.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
