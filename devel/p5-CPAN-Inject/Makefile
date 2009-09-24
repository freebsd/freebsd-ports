# New ports collection makefile for:	p5-CPAN-Inject
# Date created:				September 21st 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	CPAN-Inject
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Base class for injecting distributions into CPAN sources

BUILD_DEPENDS=	p5-File-chmod>=0.30:${PORTSDIR}/devel/p5-File-chmod \
		p5-Params-Util>=0.21:${PORTSDIR}/devel/p5-Params-Util \
		p5-CPAN-Checksums>=1.05:${PORTSDIR}/devel/p5-CPAN-Checksums
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		cpaninject.1
MAN3=		CPAN::Inject.3

.include <bsd.port.mk>
