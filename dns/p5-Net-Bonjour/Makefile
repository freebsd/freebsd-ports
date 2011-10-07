# New ports collection makefile for:	Net-Bonjour
# Date created:		2011-04-05
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Bonjour
PORTVERSION=	0.96
CATEGORIES=	dns net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHLIGE
PKGNAMEPREFIX=	p5-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Module for DNS service discovery

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

BUILD_DEPENDS=	p5-Net-DNS>=0.5:${PORTSDIR}/dns/p5-Net-DNS

RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Net::Rendezvous.3        \
	Net::Bonjour::Entry.3    \
	Net::Rendezvous::Entry.3 \
	Net::Bonjour.3

post-patch:
	@${REINPLACE_CMD} -e 's/my $$ans = .*/my $$ans = "n";/g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
