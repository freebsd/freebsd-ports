PORTNAME=	jaxb-impl
DISTVERSION=	2.3.6	# Please check compatibility with math/scilab
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/com/sun/xml/bind/jaxb-impl/${PORTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Eclipse Implementation of JAXB
WWW=		https://github.com/eclipse-ee4j/jaxb-ri

LICENSE=	BSD3CLAUSE

USES=		java:run

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar	\
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
