PORTNAME=	javacpp
DISTVERSION=	1.5.13
CATEGORIES=	java devel
MASTER_SITES=	https://repo1.maven.org/maven2/org/bytedeco/${PORTNAME}/${DISTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	markus.graf@markusgraf.net
COMMENT=	Java-C++ bridge generator
WWW=		https://github.com/bytedeco/javacpp

LICENSE=	APACHE20

USES=		java

ONLY_FOR_ARCHS=	amd64
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/${DISTNAME}.jar \
		${JAVAJARDIR}/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/
	${LN} -sf ${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
