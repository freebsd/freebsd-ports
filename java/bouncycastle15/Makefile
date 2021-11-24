# Created by: Eugene Grosbein <ports@grosbein.net>

PORTNAME=	bouncycastle
PORTVERSION=	1.69
CATEGORIES=	java security
MASTER_SITES=	http://www.bouncycastle.org/download/ \
		http://polydistortion.net/bc/download/
PKGNAMESUFFIX=	15
DISTNAME=	crypto-${DVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cleanroom build of Java Cryptography Extensions

# APACHE20 is used by pg/src/main/java/org/bouncycastle/apache/bzip2/*.
LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.html

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:java/junit \
		${JAVALIBDIR}/mail.jar:java/javamail
RUN_DEPENDS=	${JAVALIBDIR}/mail.jar:java/javamail

USES=		cpe
CPE_VENDOR=	${PORTNAME}
CPE_PRODUCT=	legion-of-the-bouncy-castle-java-crytography-api
USE_ANT=	yes
USE_JAVA=	yes

MAKE_ARGS=	-f \
		ant/jdk${JDKNVERSION}+.xml
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES
ALL_TARGET=	build-provider build zip-src

CONFLICTS_INSTALL=	bouncycastle-1.4*

NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS ZIPSRC
OPTIONS_DEFAULT=	ZIPSRC
OPTIONS_SUB=		yes

ZIPSRC_DESC=	Install bundled ZIP source files

DVERSION=	${PORTVERSION:S/.//}
JDKMVERSION=	1.5
JDKNVERSION=	15
JARS_SRC=	bcmail bcpkix bcprov bcpg
JARS_DOCS=	${JARS_SRC} bctest bctls
JARS=		${JARS_DOCS} bcprov-ext

.include <bsd.port.options.mk>

# PR 220612: remove fork="true" in javac and fork="yes" in junit tasks
.if ${ARCH} == armv6 || ${ARCH} == armv7
EXTRA_PATCHES+=	${FILESDIR}/armv6-patch-bc+-build.xml
.endif

do-install:
.for jar in ${JARS}
	${INSTALL_DATA} ${WRKSRC}/build/artifacts/jdk${JDKMVERSION}/jars/${jar}-jdk${JDKNVERSION}on-${DVERSION}.jar \
	      ${STAGEDIR}${JAVAJARDIR}/${jar}.jar
.endfor
	${INSTALL_DATA} ${WRKSRC}/jars/bcprov-jdk${JDKNVERSION}on-${DVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/bcprov.jar
.if ${PORT_OPTIONS:MZIPSRC}
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for jar in ${JARS_SRC}
	${INSTALL_DATA} ${WRKSRC}/build/artifacts/jdk${JDKMVERSION}/${jar}-jdk${JDKNVERSION}on-${DVERSION}/src.zip \
	      ${STAGEDIR}${DATADIR}/${jar}-src.zip
.endfor
.endif

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR}
.for jar in ${JARS_DOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${jar}
	@cd ${WRKSRC}/build/artifacts/jdk${JDKMVERSION}/${jar}-jdk${JDKNVERSION}on-${DVERSION}/docs/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${jar}
.endfor

.include <bsd.port.mk>
