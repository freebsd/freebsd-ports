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

BUILD_DEPENDS=	Test-More:${PORTSDIR}/devel/p5-Test-Simple \
		Test-Pod:${PORTSDIR}/devel/p5-Test-Pod \
		Test-Pod-Coverage:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS=	Data-Dumper:${PORTSDIR}/devel/p5-Data-Dumper \
		ExtUtils-MakeMaker:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		File-Spec:${PORTSDIR}/devel/p5-PathTools \
		File-Slurp:${PORTSDIR}/devel/p5-File-Slurp \
		File-HomeDir:${PORTSDIR}/devel/p5-File-HomeDir

PERL_MODBUILD=	yes

MAN3=		Module::Build::Convert.3
MAN1=		make2build.1

.include <bsd.port.mk>
