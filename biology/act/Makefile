# New ports collection makefile for:	artemis
# Date created:				11 Mar 2002
# Whom:					chuynh@bilateral.com.au
#
# $FreeBSD$
#

PORTNAME=	act
PORTVERSION=	1.0
CATEGORIES=	biology
MASTER_SITES=	http://www.sanger.ac.uk/Software/ACT/v1/
DISTNAME=	act_compiled_v1

MAINTAINER=	chuynh@biolateral.com.au

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
