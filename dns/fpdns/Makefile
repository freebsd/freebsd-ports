# New ports collection makefile for:	fpdns
# Date Created:				July 2 2004
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	fpdns
PORTVERSION=	0.9.0
CATEGORIES=	dns
MASTER_SITES=	http://www.rfc.se/fpdns/distfiles/
DISTFILES=	${PORTNAME}-${PORTVERSION}.gz

MAINTAINER=	edwin@mavetju.org
COMMENT=	FPDNS - Fingerprinting DNS servers

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_PERL5_RUN=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"Requires at least Perl version 5.6.0"
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	${GZCAT} ${DISTDIR}/${DISTFILES} > ${WRKDIR}/fpdns.pl

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/fpdns.pl ${PREFIX}/bin/fpdns

.include <bsd.port.post.mk>
