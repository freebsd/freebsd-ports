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
COMMENT=	A Java benchmark for scientific and numerical computing

WRKSRC=		${WRKDIR}
USE_ZIP=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NEED_JAVAC=	yes
JAVAC_OPTS?=	-O

LSMDIR=		share/java/scimark2
SMDIR=		${PREFIX}/${LSMDIR}

SMSH=		${PORTNAME}${PKGNAMESUFFIX}

PLIST_SUB=	SMDIR=${LSMDIR}
PKGMESSAGE=	${WRKSRC}/pkg-message

NO_STAGE=	yes
do-build:
	cd ${WRKSRC} && ${JAVAC} ${JAVAC_OPTS} commandline.java
	@${CP} ${WRKSRC}/commandline.class ${WRKSRC}/jnt/scimark2

do-install:
	@${MKDIR} ${SMDIR}
	@${CP} -R ${WRKSRC}/jnt ${SMDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${SMDIR}
	@${ECHO} "#!/bin/sh" > ${WRKSRC}/${SMSH}
	@${ECHO} "cd ${SMDIR} && ${JAVA} jnt.scimark2.commandline" '$$1' >> ${WRKSRC}/${SMSH}
	@${INSTALL_SCRIPT} ${WRKSRC}/${SMSH} ${PREFIX}/bin

post-install:
	@${SED} -e 's|%%SMSH%%|${SMSH}|g' ${FILESDIR}/pkg-message.in	\
		> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
