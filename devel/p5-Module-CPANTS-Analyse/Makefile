# New ports collection makefile for:	p5-Module-CPANTS-Analyse
# Date created:				Feb 13 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	Module-CPANTS-Analyse
PORTVERSION=	0.77
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Generate Kwalitee ratings for a distribution

BUILD_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep
RUN_DEPENDS=	p5-Archive-Any>=0.06:${PORTSDIR}/archivers/p5-Archive-Any \
		p5-Array-Diff>=0.04:${PORTSDIR}/misc/p5-Array-Diff \
		p5-CPAN-DistnameInfo>=0.06:${PORTSDIR}/devel/p5-CPAN-DistnameInfo \
		p5-Class-Accessor>=0.19:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-IO-Capture>=0.05:${PORTSDIR}/devel/p5-IO-Capture \
		p5-Module-ExtractUse>=0.18:${PORTSDIR}/devel/p5-Module-ExtractUse \
		p5-Test-YAML-Meta>=0.06:${PORTSDIR}/devel/p5-Test-YAML-Meta \
		p5-YAML-Syck>=0.95:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-version>=0.73:${PORTSDIR}/devel/p5-version

PERL_MODBUILD=	yes

MAN1=		cpants_lint.pl.1
MAN3=		Module::CPANTS::Analyse.3 \
		Module::CPANTS::Kwalitee.3 \
		Module::CPANTS::Kwalitee::BrokenInstaller.3 \
		Module::CPANTS::Kwalitee::CpantsErrors.3 \
		Module::CPANTS::Kwalitee::Distname.3 \
		Module::CPANTS::Kwalitee::Files.3 \
		Module::CPANTS::Kwalitee::FindModules.3 \
		Module::CPANTS::Kwalitee::License.3 \
		Module::CPANTS::Kwalitee::Manifest.3 \
		Module::CPANTS::Kwalitee::MetaYML.3 \
		Module::CPANTS::Kwalitee::NeedsCompiler.3 \
		Module::CPANTS::Kwalitee::Pod.3 \
		Module::CPANTS::Kwalitee::Prereq.3 \
		Module::CPANTS::Kwalitee::Uses.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-Pod-Simple>=0:${PORTSDIR}/textproc/p5-Pod-Simple
.endif

.if ${PERL_LEVEL} < 500905
RUN_DEPENDS+=	p5-Module-Pluggable>=2.96:${PORTSDIR}/devel/p5-Module-Pluggable
.endif

.include <bsd.port.post.mk>
