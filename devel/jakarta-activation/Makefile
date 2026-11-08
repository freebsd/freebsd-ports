PORTNAME=	jakarta.activation
DISTVERSION=	2.0.1	# Please check compatibility with math/scilab
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/com/sun/activation/jakarta.activation/${PORTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Jakarta Activation
WWW=		https://jakarta.ee/specifications/activation/

LICENSE=	BSD3CLAUSE

USES=		java:run

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${DISTNAME}.jar

do-install:
# Don't install jakarta.activation.jar to avoid a conflict with java/javamail
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar	\
		${STAGEDIR}${JAVAJARDIR}/

.include <bsd.port.mk>
