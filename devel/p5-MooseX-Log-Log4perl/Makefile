# New ports collection makefile for:	devel/p5-MooseX-Log-Log4perl
# Date created:				25 February 2009
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Log-Log4perl
PORTVERSION=	0.43
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A logging role for Moose based on Log::Log4perl

BUILD_DEPENDS=	p5-Any-Moose>=0.12:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Log-Log4perl>=1.13:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-IO-stringy>0:${PORTSDIR}/devel/p5-IO-stringy

PERL_CONFIGURE=	yes

MAN3=		MooseX::Log::Log4perl.3 \
		MooseX::Log::Log4perl::Easy.3

post-patch:
	@${PERL} -pi -e '$$_="" if m/auto_install/' ${WRKSRC}/Makefile.PL

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

.include <bsd.port.mk>
