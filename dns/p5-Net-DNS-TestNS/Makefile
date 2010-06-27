# New ports collection makefile for:	p5-Net-DNS-TestNS
# Date created:		2010-06-26
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	Net-DNS-TestNS
PORTVERSION=	1.10
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN/../../authors/id/O/OL/OLAF/
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Perl extension for simulating simple Nameservers

BUILD_DEPENDS=	p5-Net-DNS>0.64:${PORTSDIR}/dns/p5-Net-DNS \
		p5-XML-LibXML>1.53:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::DNS::TestNS.3 Net::DNS::TestNS::DTD.3

.include <bsd.port.mk>
