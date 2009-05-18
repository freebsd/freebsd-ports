# New ports collection makefile for:	devel/p5-MooseX-Log-Log4perl
# Date created:				25 February 2009
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Log-Log4perl
PORTVERSION=	0.40
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A logging role for Moose based on Log::Log4perl

RUN_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Log::Log4perl.3 \
		MooseX::Log::Log4perl::Easy.3

post-patch:
	@${PERL} -pi -e '$$_="" if m/auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
