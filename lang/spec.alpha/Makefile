# $FreeBSD$

PORTNAME=	spec.alpha
DISTVERSION=	0.1.143
CATEGORIES=	lang lisp java
MASTER_SITES=	http://repo1.maven.org/maven2/org/clojure/spec.alpha/${PORTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	jan0sch@mykolab.com
COMMENT=	Clojure library to describe the structure of data and functions

LICENSE=	EPL

USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes
PLIST_FILES=	${JAVAJARDIR}/spec.alpha.jar

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${JAVAJARDIR}/spec.alpha.jar

.include <bsd.port.mk>
