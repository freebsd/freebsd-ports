# New ports collection makefile for:	pmd
# Date created:				2006-06-07
# Whom:	      				Alex Varju <freebsd-ports@varju.ca>
#
# $FreeBSD$
#

PORTNAME=	pmd
PORTVERSION=	3.7
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	freebsd-ports@varju.ca
COMMENT=	Static analysis tool for Java source code

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_ANT=	yes

MAKE_ARGS=	-cp ${JAVALIBDIR}/junit.jar

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/bin

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
.for script in bgastviewer.sh cpd.sh designer.sh pmd.sh
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|" \
	  -e "s|%%JAVA_VERSION%%|${JAVA_VERSION}|" \
	  -e "s|%%LOCALBASE%%|${LOCALBASE}|" \
	  ${INSTALL_WRKSRC}/bin/${script}
.endfor
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/bin/bgastviewer.sh ${PREFIX}/bin/bgastviewer
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/bin/cpd.sh ${PREFIX}/bin/cpd
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/bin/designer.sh ${PREFIX}/bin/pmd_designer
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/bin/pmd.sh ${PREFIX}/bin/pmd
	${MKDIR} ${DATADIR}
	cd ${INSTALL_WRKSRC}/lib \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DATADIR}/ \;
.if !defined(NOPORTDOCS)
	cd ${INSTALL_WRKSRC}/docs \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

.include <bsd.port.post.mk>
