# New ports collection makefile for:	p5-POE-Component-Server-DNS
# Date created:		2007-02-23
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-DNS
PORTVERSION=	0.20
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Non-blocking, concurrent DNS server component

RUN_DEPENDS=	p5-POE>=0.38:${PORTSDIR}/devel/p5-POE \
		p5-Net-DNS>=0.58:${PORTSDIR}/dns/p5-Net-DNS \
		p5-POE-Component-Client-DNS>=1.00:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
		p5-POE-Component-Generic>=0.09.10:${PORTSDIR}/net/p5-POE-Component-Generic

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Server::DNS.3

.include <bsd.port.mk>
