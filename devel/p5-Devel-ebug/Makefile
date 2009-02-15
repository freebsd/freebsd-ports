# New ports collection makefile for:	p5-Devel-ebug
# Date created:		2007-05-02
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-ebug
PORTVERSION=	0.49
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A simple, extensible Perl debugger

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/PadWalker.pm:${PORTSDIR}/devel/p5-PadWalker \
		${SITE_PERL}/${PERL_ARCH}/YAML/Syck.pm:${PORTSDIR}/textproc/p5-YAML-Syck \
		${SITE_PERL}/Class/Accessor/Chained/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		${SITE_PERL}/Devel/StackTrace.pm:${PORTSDIR}/devel/p5-Devel-StackTrace \
		${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable \
		${SITE_PERL}/Proc/Background.pm:${PORTSDIR}/devel/p5-Proc-Background \
		${SITE_PERL}/String/Koremutake.pm:${PORTSDIR}/textproc/p5-String-Koremutake
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		ebug.1 ebug_client.1 ebug_server.1
MAN3=		Devel::ebug.3 Devel::ebug::Console.3

.include <bsd.port.mk>
