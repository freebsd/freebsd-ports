# New ports collection makefile for:	jzip
# Date created:				7 May 1998
# Whom:					Matthew Hunt <mph@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		jzip
PORTVERSION=		2.0.1g
CATEGORIES=		games
MASTER_SITES=   	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mph
DISTNAME=		jzip201g

MAINTAINER=		mph@freebsd.org
COMMENT=	A text-mode Infocom game interpreter

USE_ZIP=		yes

NO_WRKSUBDIR=		yes

MAN1=			jzip.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jzip ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/jzip.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jzip
	${INSTALL_DATA} ${WRKSRC}/Jzip.doc ${PREFIX}/share/doc/jzip
.endif

.include <bsd.port.mk>
