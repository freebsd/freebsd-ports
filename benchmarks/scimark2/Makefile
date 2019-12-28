# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	scimark2
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	benchmarks java
MASTER_SITES=	http://math.nist.gov/scimark2/
PKGNAMESUFFIX=	-java
DISTNAME=	${PORTNAME}src

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Java benchmark for scientific and numerical computing

LICENSE=	PD

USES=		zip
USE_JAVA=	yes
NEED_JAVAC=	yes
JAVAC_OPTS?=	-O
NO_ARCH=	yes

LSMDIR=		share/java/scimark2
SMDIR=		${PREFIX}/${LSMDIR}

SMSH=		${PORTNAME}${PKGNAMESUFFIX}

NO_WRKSUBDIR=	yes
PLIST_SUB=	SMDIR=${LSMDIR}
SUB_FILES=	pkg-message
SUB_LIST=	SMSH=${SMSH}

do-build:
	cd ${WRKSRC} && ${JAVAC} ${JAVAC_OPTS} commandline.java
	${CP} ${WRKSRC}/commandline.class ${WRKSRC}/jnt/scimark2

do-install:
	${MKDIR} ${STAGEDIR}${SMDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} jnt ${STAGEDIR}${SMDIR}/
	${ECHO_CMD} "#! /bin/sh" > ${WRKSRC}/${SMSH}
	${ECHO_CMD} "cd ${SMDIR} && ${JAVA} jnt.scimark2.commandline" '$$1' >> ${WRKSRC}/${SMSH}
	${INSTALL_SCRIPT} ${WRKSRC}/${SMSH} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
