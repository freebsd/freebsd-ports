# $FreeBSD$

PORTNAME=	c3p0
PORTVERSION=	0.9.1.2
CATEGORIES=	databases java
MASTER_SITES=	SF/c3p0/c3p0-bin/c3p0-${PORTVERSION}/
DISTNAME=	c3p0-${PORTVERSION}.bin
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A library for augmenting JDBC drivers with JNDI-bindable DataSources

USE_JAVA=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.6+
WRKSRC=		${WRKDIR}/c3p0-${PORTVERSION}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/c3p0-0.9.1.2.jar ${JAVAJARDIR}/c3p0.jar
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} apidocs ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/arrow_sm.png ${WRKSRC}/doc/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
