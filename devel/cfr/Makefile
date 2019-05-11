# $FreeBSD$

PORTNAME=	cfr
DISTVERSION=	0.144
CATEGORIES=	devel java
MASTER_SITES=	https://www.benf.org/other/cfr/ \
		http://www.benf.org/other/cfr/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Class File Reader (CFR) Java decompiler

# http://www.benf.org/other/cfr/license.html
LICENSE=	MIT

USE_JAVA=	yes
JAVA_RUN=	jre

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${JAVAJARDIR}/cfr.jar

JARFILE=	${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${JAVAJARDIR}/${JARFILE}

do-test:
	# Find out if the decompiler works.
	${JAVA} -jar ${STAGEDIR}${JAVAJARDIR}/${JARFILE} \
		${STAGEDIR}${JAVAJARDIR}/${JARFILE} >/dev/null

.include <bsd.port.mk>
