# New ports collection makefile for:	ExtUtils::CChecker
# Date created:				21 Feb 2010
# Whom:                			Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-CChecker
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	Configure-time utilities for using C headers, libraries, OS features

PERL_CONFIGURE=	yes

MAN3=		ExtUtils::CChecker.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${INSTALL} -o ${DOCOWN} -g ${DOCGRP} -m 555 -d ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
