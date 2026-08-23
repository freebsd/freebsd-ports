PORTNAME=	c3p0
PORTVERSION=	0.9.5.5
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-bin/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}.bin

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Library for augmenting JDBC drivers with JNDI-bindable DataSources
WWW=		https://www.mchange.com/projects/c3p0/

LICENSE=	EPL LGPL21
LICENSE_COMB=	dual

USES=		cpe java tar:tgz
CPE_VENDOR=	mchange
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} apidocs-oracle-thin ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/arrow_sm.png ${WRKSRC}/doc/index.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
