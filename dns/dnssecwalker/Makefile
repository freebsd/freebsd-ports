# ex:ts=8
# Ports collection makefile for:	dnssecwalk
# Date created:			Feb 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dnssecwalker
PORTVERSION=	2.0
CATEGORIES=	dns
MASTER_SITES=	http://josefsson.org/walker/
DISTNAME=	walker-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DNSSEC Walker

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS

USE_PERL5=	yes
NO_BUILD=	yes

CONFLICTS=	walker-1.*

MAN1=		walker.1
PLIST_FILES=	bin/walker

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/walker ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/walker.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
