# New ports collection makefile for:		gnu-regexp
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	gnu-regexp
PORTVERSION=	1.1.4
CATEGORIES=	java devel
MASTER_SITES=	ftp://ftp.tralfamadore.com/pub/java/
DISTNAME=	gnu.regexp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_JAVA=	1.1+

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
