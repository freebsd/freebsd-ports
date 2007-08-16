# New ports collection makefile for:	Module::Build::Convert
# Date created:				Apr 27 2006
# Whom:                			clsung
#
# $FreeBSD$
#

PORTNAME=	Module-Build-Convert
PORTVERSION=	0.49
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Makefile.PL to Build.PL converter

BUILD_DEPENDS=	p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir

PERL_MODBUILD=	yes

MAN3=		Module::Build::Convert.3
MAN1=		make2build.1

.include <bsd.port.mk>
