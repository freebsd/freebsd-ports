# ex:ts=8
# Ports collection makefile for:	dnssecwalk
# Date created:			Feb 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dnssecwalker
PORTVERSION=	2.0
CATEGORIES=	net
MASTER_SITES=	http://josefsson.org/walker/
DISTNAME=	walker-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=	walker.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/walker ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/walker.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
