# ex:ts=8
# New ports collection makefile for:	walker
# Date created:			May 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	walker
PORTVERSION=	3.5
CATEGORIES=	dns
MASTER_SITES=	http://josefsson.org/${PORTNAME}/releases/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	johans@stack.nl
COMMENT=	Recover zone file information from servers that use DNSSEC

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Net/DNS/SEC.pm:${PORTSDIR}/dns/p5-Net-DNS-SEC

USE_PERL5=	yes
NO_BUILD=	yes
USE_GPG?=	yes
SIG_FILES=	${DISTNAME}${EXTRACT_SUFX}.sig

MAN1=		walker.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/walker ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
