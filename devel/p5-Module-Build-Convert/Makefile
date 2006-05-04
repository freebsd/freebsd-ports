# New ports collection makefile for:	Module::Build::Convert
# Date created:				Apr 27 2006
# Whom:                			clsung
#
# $FreeBSD$
#

PORTNAME=	Module-Build-Convert
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Makefile.PL to Build.PL converter

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS=	p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-ExtUtils-MakeMaker>=0:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir

PERL_MODBUILD=	yes

MAN3=		Module::Build::Convert.3
MAN1=		make2build.1

.include <bsd.port.mk>
