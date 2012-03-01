# New ports collection makefile for:	p5-POE-Component-Client-DNSBL
# Date created:		2012-03-01
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-DNSBL
PORTVERSION=	1.08
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Perl POE component that provides non-blocking DNSBL lookups

BUILD_DEPENDS=	p5-POE>=1.004:${PORTSDIR}/devel/p5-POE \
		p5-Net-IP-Minimal>=0:${PORTSDIR}/net/p5-Net-IP-Minimal \
		p5-POE-Component-Client-DNS>=0:${PORTSDIR}/dns/p5-POE-Component-Client-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POE::Component::Client::DNSBL.3

.include <bsd.port.mk>
