# New ports collection makefile for:	POE-Component-Client-DNS
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-DNS
PORTVERSION=	1.050
PORTEPOCH=	1
CATEGORIES=	dns perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	POE component for non-blocking/concurrent DNS queries

BUILD_DEPENDS=	p5-POE>=1.007:${PORTSDIR}/devel/p5-POE \
		p5-Net-DNS>=0.59:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Client::DNS.3

.include <bsd.port.mk>
