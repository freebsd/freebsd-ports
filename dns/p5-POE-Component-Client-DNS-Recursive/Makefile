# New ports collection makefile for:	p5-POE-Component-Client-DNS-Recursive
# Date created:		2012-02-28
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-DNS-Recursive
PORTVERSION=	1.02
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A recursive DNS client for POE

BUILD_DEPENDS=	p5-POE>=1.004:${PORTSDIR}/devel/p5-POE \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-IP-Minimal>=0:${PORTSDIR}/net/p5-Net-IP-Minimal
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POE::Component::Client::DNS::Recursive.3

.include <bsd.port.mk>
