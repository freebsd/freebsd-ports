# ex:ts=8
# Ports collection makefile for:	dnssecwalk
# Date created:			Feb 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dnssecwalker
PORTVERSION=	3.5
CATEGORIES=	dns
MASTER_SITES=	http://josefsson.org/walker/releases/
DISTNAME=	walker-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	johans@stack.nl
COMMENT=	DNSSEC Walker

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS\
		${SITE_PERL}/Net/DNS/SEC.pm:${PORTSDIR}/dns/p5-Net-DNS-SEC

USE_PERL5=	yes
NO_BUILD=	yes
USE_GPG?=	yes
SIG_FILES=	${DISTNAME}${EXTRACT_SUFX}.sig

CONFLICTS=	walker-1.*

MAN1=		walker.1
PLIST_FILES=	bin/walker

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/walker ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/walker.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
