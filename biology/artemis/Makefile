# New ports collection makefile for:	artemis
# Date created:				10 Nov 2001
# Whom:					camson@bilateral.com.au
#
# $FreeBSD$
#

PORTNAME=	artemis
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.sanger.ac.uk/Software/Artemis/v4/
DISTNAME=	artemis_compiled_v4

MAINTAINER=	chuynh@biolateral.com.au
COMMENT=	A DNA sequence viewer and annotation tool

RUN_DEPENDS=	${JAVA_COMMAND}:${PORTSDIR}/java/jdk13

WRKSRC=		${WRKDIR}/${PORTNAME}

JDK_VERSION=	1.3.1
JDK_DIR=	${PREFIX}/jdk${JDK_VERSION}
JAVA_COMMAND=	${JDK_DIR}/bin/java

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}-${PORTVERSION}
	@${TAR} -C ${WRKSRC} -cf- . | ${TAR} -C ${PREFIX}/${PORTNAME}-${PORTVERSION} -xpf-
	@${LN} -s ${PREFIX}/${PORTNAME}-${PORTVERSION}/art ${PREFIX}/bin/art

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
