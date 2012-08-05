# New ports collection makefile for:	p5-Devel-ebug
# Date created:		2007-05-02
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-ebug
PORTVERSION=	0.53
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A simple, extensible Perl debugger

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-PadWalker>0:${PORTSDIR}/devel/p5-PadWalker \
		p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-Class-Accessor-Chained>0:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		p5-Devel-StackTrace>0:${PORTSDIR}/devel/p5-Devel-StackTrace \
		p5-Proc-Background>0:${PORTSDIR}/devel/p5-Proc-Background \
		p5-String-Koremutake>0:${PORTSDIR}/textproc/p5-String-Koremutake
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML \
		p5-Test-Expect>=0:${PORTSDIR}/devel/p5-Test-Expect

PERL_MODBUILD=	yes

MAN1=		ebug.1 ebug_client.1 ebug_server.1
MAN3=		Devel::ebug.3 Devel::ebug::Console.3

.include <bsd.port.mk>
