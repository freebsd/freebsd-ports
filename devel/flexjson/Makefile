# Created by: Nemo Liu <nemoliu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flexjson
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Flexjson%201.0
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight Java library to write JSON

OPTIONS_DEFINE=	DOCS
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	LICENSE-2.0.txt docs

do-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

	@${MKDIR} ${STAGEDIR}${DOCSDIR}/docs/
	@cd ${WRKDIR}/docs \
	  && ${INSTALL_DATA} example_object_model.jpg ${STAGEDIR}${DOCSDIR}/docs/. \
	  && ${INSTALL_DATA} index.html ${STAGEDIR}${DOCSDIR}/docs/.
	@${INSTALL_DATA} ${WRKDIR}/LICENSE-2.0.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
