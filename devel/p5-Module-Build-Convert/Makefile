# New ports collection makefile for:	Module::Build::Convert
# Date created:				Apr 27 2006
# Whom:                			clsung
#
# $FreeBSD$
#

PORTNAME=	Module-Build-Convert
PORTVERSION=	0.28
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Makefile.PL to Build.PL converter

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper \
		${SITE_PERL}/ExtUtils/MakeMaker.pm:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
		${SITE_PERL}/File/HomeDir.pm:${PORTSDIR}/devel/p5-File-HomeDir

PERL_MODBUILD=	yes

MAN3=		Module::Build::Convert.3
MAN1=		make2build.1

.include <bsd.port.mk>
