# New ports collection makefile for:	dns/p5-Net-DNS-ZoneFile-Fast
# Date created:				14 October 2004
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-DNS-ZoneFile-Fast
PORTVERSION=	1.14
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to parse BIND8/9 zone files

RUN_DEPENDS=	p5-Net-DNS>=0.65:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-DNS-SEC>=0.15:${PORTSDIR}/dns/p5-Net-DNS-SEC
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Net::DNS::ZoneFile::Fast.3

.include <bsd.port.mk>
