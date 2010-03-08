# New ports collection makefile for:	p5-Eval-Context
# Date Created:				22 Apr 2008
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Eval-Context
PORTVERSION=	0.09.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/N/NK/NKH
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Evalute perl code in context wraper

BUILD_DEPENDS=	${SITE_PERL}/Test/Output.pm:${PORTSDIR}/devel/p5-Test-Output \
		${SITE_PERL}/Package/Generator.pm:${PORTSDIR}/devel/p5-Package-Generator \
		${SITE_PERL}/Test/Spelling.pm:${PORTSDIR}/devel/p5-Test-Spelling \
		${SITE_PERL}/Test/Block.pm:${PORTSDIR}/devel/p5-Test-Block \
		${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings \
		${SITE_PERL}/Test/Distribution.pm:${PORTSDIR}/devel/p5-Test-Distribution \
		${SITE_PERL}/Test/Warn.pm:${PORTSDIR}/devel/p5-Test-Warn \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Test/Dependencies.pm:${PORTSDIR}/devel/p5-Test-Dependencies \
		${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version \
		${SITE_PERL}/Test/Strict.pm:${PORTSDIR}/devel/p5-Test-Strict \
		${SITE_PERL}/Directory/Scratch/Structured.pm:${PORTSDIR}/devel/p5-Directory-Scratch-Structured \
		${SITE_PERL}/Data/TreeDumper.pm:${PORTSDIR}/devel/p5-Data-TreeDumper \
		${SITE_PERL}/Data/Compare.pm:${PORTSDIR}/devel/p5-Data-Compare \
		${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes
MAKE_JOBS_SAFE=	yes

MAN3=		Eval::Context.3

.include <bsd.port.mk>
