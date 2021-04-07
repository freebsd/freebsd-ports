PORTNAME=	c3p0
PORTVERSION=	0.9.5.3
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-bin/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}.bin

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Library for augmenting JDBC drivers with JNDI-bindable DataSources

LICENSE=	LGPL21 EPL
LICENSE_COMB=	dual

USES=		tar:tgz
USE_JAVA=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} apidocs-oracle-thin ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/arrow_sm.png ${WRKSRC}/doc/index.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
