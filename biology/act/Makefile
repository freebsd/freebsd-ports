# New ports collection makefile for:	artemis
# Date created:		10 Mar 2003
# Whom:			fernan@iib.unsam.edu.ar
#
# $FreeBSD$
#

PORTNAME=	act
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.sanger.ac.uk/Software/ACT/v2/
DISTNAME=	act_compiled_v2

MAINTAINER=	chuynh@biolateral.com.au
COMMENT=	A DNA sequence comparison viewer based on Artemis

RUN_DEPENDS=	${JAVA_COMMAND}:${PORTSDIR}/java/jdk13

WRKSRC=		${WRKDIR}/${PORTNAME}

JDK_VERSION=	1.3.1
JDK_DIR=	${PREFIX}/jdk${JDK_VERSION}
JAVA_COMMAND=	${JDK_DIR}/bin/java

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}-${PORTVERSION}
	@${TAR} -C ${WRKSRC} -cf- . | ${TAR} -C ${PREFIX}/${PORTNAME}-${PORTVERSION} -xpf-
	@${LN} -s ${PREFIX}/${PORTNAME}-${PORTVERSION}/act ${PREFIX}/bin/act

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
