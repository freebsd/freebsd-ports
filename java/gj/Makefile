# New ports collection makefile for:	gj-jdk12
# Date created:		2003-05-26
# Whom:			Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	gj
PORTVERSION=	0.6m
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	http://www.cis.unisa.edu.au/~pizza/gj/Distribution/
PKGNAMESUFFIX=	-${JDKSUBDIR}
DISTNAME=	gjdist${GJDIST}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extension of the Java programming language that supports generic types

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/gj

NO_BUILD=	YES
USE_JAVA=	yes

.if defined(GJ_WITH_JDK11)
GJDIST=		1.1
BINSUFX=	11
JAVA_VERSION=	1.1
.else
GJDIST=		1.2
JAVA_VERSION=	1.2+
.endif

JDKSUBDIR=	jdk${GJDIST}
PLIST_SUB+=	JDKSUBDIR=${JDKSUBDIR}
PLIST_FILES?=	bin/gjc bin/gjcr bin/gj

do-install:
	${MKDIR} ${PREFIX}/lib/gj/${JDKSUBDIR}
	${TAR} cf - -C ${WRKSRC}/classes . | ${TAR} xf - -C ${PREFIX}/lib/gj/${JDKSUBDIR}
	${SED}	-e s/@JDKSUBDIR@/${JDKSUBDIR}/ \
		-e 's+@PREFIX@+'${PREFIX}'+' \
		-e 's+@JAVA_HOME@+'${JAVA_HOME}'+' \
		<${FILESDIR}/gjc.in >${WRKDIR}/gjc
	${INSTALL_SCRIPT} ${WRKDIR}/gjc ${PREFIX}/bin/gjc${BINSUFX}
.for f in gjcr gj
	${LN} -sf ${PREFIX}/bin/gjc${BINSUFX} ${PREFIX}/bin/${f}${BINSUFX}
.endfor

.include <bsd.port.mk>
