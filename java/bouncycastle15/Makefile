# Created by: Eugene Grosbein <ports@grosbein.net>
# $FreeBSD$

PORTNAME=	bouncycastle
PORTVERSION=	1.54
CATEGORIES=	java security
MASTER_SITES=	http://downloads.bouncycastle.org/java/ \
		http://polydistortion.net/bc/download/ \
		http://bouncycastle.gva.es/download/
PKGNAMESUFFIX=	15
DISTNAME=	crypto-${DVERSION}

MAINTAINER=	ports@grosbein.net
COMMENT=	Cleanroom build of Java Cryptography Extensions

LICENSE=	MIT

BUILD_DEPENDS=	${JAVALIBDIR}/activation.jar:java/jaf \
		${JAVALIBDIR}/mail.jar:java/javamail \
		${JAVALIBDIR}/junit.jar:java/junit
RUN_DEPENDS=	${JAVALIBDIR}/activation.jar:java/jaf \
		${JAVALIBDIR}/mail.jar:java/javamail

OPTIONS_DEFINE=	DOCS
CONFLICTS_INSTALL=	bouncycastle-1.4*
DVERSION=	${PORTVERSION:S/.//}
NO_ARCH=	yes
CPE_PRODUCT=	legion-of-the-bouncy-castle-java-crytography-api
CPE_VENDOR=	${PORTNAME}
USE_JAVA=	yes
USES=		cpe
JAVA_VERSION=	1.6+
JDKMVERSION=	1.5
JDKNVERSION=	15
USE_ANT=	yes
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES
MAKE_ARGS=	-f ant/jdk${JDKNVERSION}+.xml
ALL_TARGET=	build-provider build zip-src

JARS_SRC=	bcmail bcpkix bcprov bcpg
JARS_DOCS=	${JARS_SRC} bctest
JARS=		${JARS_DOCS} bcprov-ext

PORTDOCS=	*

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for jar in ${JARS}
	${INSTALL_DATA} ${WRKSRC}/build/artifacts/jdk${JDKMVERSION}/jars/${jar}-jdk${JDKNVERSION}on-${DVERSION}.jar \
	      ${STAGEDIR}${JAVAJARDIR}/${jar}.jar
.endfor
.for jar in ${JARS_SRC}
	${INSTALL_DATA} ${WRKSRC}/build/artifacts/jdk${JDKMVERSION}/${jar}-jdk${JDKNVERSION}on-${DVERSION}/src.zip \
	      ${STAGEDIR}${DATADIR}/${jar}-src.zip
.endfor
	${INSTALL_DATA} ${WRKSRC}/jars/bcprov-jdk${JDKNVERSION}on-${DVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/bcprov.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR}
.for jar in ${JARS_DOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${jar}
	@cd ${WRKSRC}/build/artifacts/jdk${JDKMVERSION}/${jar}-jdk${JDKNVERSION}on-${DVERSION}/docs/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${jar}
.endfor

.include <bsd.port.mk>
