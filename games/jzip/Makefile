# New ports collection makefile for:	jzip
# Version required:			2.0.1g
# Date created:				7 May 1998
# Whom:					Matthew Hunt <mph@FreeBSD.org>
#
# $Id: Makefile,v 1.1.1.1 1998/05/08 02:38:34 mph Exp $
#

DISTNAME=		jzip201g
PKGNAME=		jzip-2.0.1g
CATEGORIES=		games
MASTER_SITES=   	http://www.cfug.org/infocom/
EXTRACT_SUFX=		.zip

MAINTAINER=		mph@freebsd.org

BUILD_DEPENDS=		unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	-qq

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
