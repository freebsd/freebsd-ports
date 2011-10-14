# New ports collection makefile for:	p5-Devel-CheckLib
# Date created:				08 August 2010
# Whom:					Frederic Culot <frederic@culot.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-CheckLib
PORTVERSION=	0.94
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl5 module to check that a library is available

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-CaptureOutput>=1.08:${PORTSDIR}/devel/p5-IO-CaptureOutput
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		use-devel-checklib.1
MAN3=		Devel::CheckLib.3

.include <bsd.port.mk>
