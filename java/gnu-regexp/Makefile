# New ports collection makefile for:		gnu-regexp
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	gnu-regexp
PORTVERSION=	1.0.8
CATEGORIES=	java devel
MASTER_SITES=	ftp://ftp.tralfamadore.com/pub/java/
DISTNAME=	gnu.regexp-${PORTVERSION}

MAINTAINER=	freebsd-ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk11
RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk11

NO_BUILD=	yes

DOCDIR=		${PREFIX}/share/doc/${PORTNAME}

CPIO?=		/usr/bin/cpio

do-install:
	${MKDIR} ${DOCDIR}
	cd ${WRKSRC}/docs && ${FIND} . \
	    | ${CPIO} -pdmu -R ${DOCOWN}:${DOCGRP} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${PORTVERSION}.jar \
	    ${PREFIX}/share/java/classes/${PORTNAME}.jar

.include <bsd.port.mk>
