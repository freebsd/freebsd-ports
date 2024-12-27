PORTNAME=	bouncycastle
PORTVERSION=	1.45
PORTREVISION=	3
CATEGORIES=	java security
MASTER_SITES=	http://downloads.bouncycastle.org/java/ \
		http://polydistortion.net/bc/download/ \
		http://bouncycastle.gva.es/download/
DISTNAME=	crypto-${JARVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Cleanroom build of Java Cryptography Extensions
WWW=		https://www.bouncycastle.org/

DEPRECATED=	Outdated and unsupported upstream, please use java/bouncycastle15 instead
EXPIRATION_DATE=2024-12-31

BUILD_DEPENDS=	${JAVALIBDIR}/mail.jar:java/javamail \
		${JAVALIBDIR}/junit.jar:java/junit
RUN_DEPENDS=	${JAVALIBDIR}/mail.jar:java/javamail

OPTIONS_DEFINE=	DOCS

USES=		cpe java:ant
CPE_PRODUCT=	legion-of-the-bouncy-castle-java-crytography-api
CPE_VENDOR=	${PORTNAME}
JDKMVERSION=	1.6 # ${JAVA_PORT_VERSION:C/^([0-9]\.[0-9])(.*)$/\1/}
JDKNVERSION=	16 # ${JAVA_PORT_VERSION:C/^([0-9])\.([0-9])(.*)$/\1\2/}
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES
MAKE_ARGS=	-f jdk${JDKNVERSION}.xml
ALL_TARGET=	build-provider build zip-src
JARVERSION=	${PORTVERSION:S/.//}

JARS=		bcprov bcmail bctsp bcpg

PORTDOCS=	*

PORTSCOUT=	skipv:146

post-patch:
	@${REINPLACE_CMD} s/BERConstructedOctetString/DEROctetString/ \
		${WRKSRC}/src/org/bouncycastle/cms/CMS*DataGenerator.java
	@${REINPLACE_CMD} 's/<javac/<javac encoding="UTF-8"/;s/<javadoc/<javadoc encoding="UTF-8"/' \
		${WRKSRC}/bc-build.xml ${WRKSRC}/common.xml

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for jar in ${JARS}
	${INSTALL_DATA} ${WRKSRC}/build/artifacts/jdk${JDKMVERSION}/jars/${jar}-jdk${JDKNVERSION}-${JARVERSION}.jar \
	      ${STAGEDIR}${JAVAJARDIR}/${jar}.jar
	${INSTALL_DATA} ${WRKSRC}/build/artifacts/jdk${JDKMVERSION}/${jar}-jdk${JDKNVERSION}-${JARVERSION}/src.zip \
	      ${STAGEDIR}${DATADIR}/${jar}-src.zip
.endfor
	${INSTALL_DATA} ${WRKSRC}/jars/bcprov-jdk${JDKNVERSION}-${JARVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/bcprov.jar
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR}
.for jar in ${JARS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${jar}
	@cd ${WRKSRC}/build/artifacts/jdk${JDKMVERSION}/${jar}-jdk${JDKNVERSION}-${JARVERSION}/docs/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${jar}
.endfor

.include <bsd.port.mk>
