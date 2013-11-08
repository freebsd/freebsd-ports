# $FreeBSD$

PORTNAME=	c3p0
PORTVERSION=	0.9.2
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-bin/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}.bin
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Library for augmenting JDBC drivers with JNDI-bindable DataSources

USE_JAVA=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.6+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} apidocs-oracle-thin ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/arrow_sm.png ${WRKSRC}/doc/index.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
