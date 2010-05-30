# New ports collection makefile for:	pg_filedump
# Date created:		18 Aug 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pg_filedump
PORTVERSION=	8.3
CATEGORIES=	databases
MASTER_SITES=	http://sources.redhat.com/rhdb/tools/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Utility to format PostgreSQL heap, index, etc into human-readable form

BUILD_DEPENDS=	\
	${NONEXISTENT}:${PORTSDIR}/databases/postgresql83-client:patch

BROKEN=		does not build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pg_filedump ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.pg_filedump ${DOCSDIR}
.endif

.include <bsd.port.mk>
