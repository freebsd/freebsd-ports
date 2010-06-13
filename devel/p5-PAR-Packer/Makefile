# New ports collection makefile for:	devel/p5-PAR-Packer
# Date created:				Dec 06 2006
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PAR-Packer
PORTVERSION=	1.00.5
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9])$/\1/}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	PAR Packager

BUILD_DEPENDS=	p5-Archive-Zip>=1.00:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-Compress-Zlib>=1.30:${PORTSDIR}/archivers/p5-Compress-Zlib \
		p5-Getopt-ArgvFile>=1.07:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-Module-ScanDeps>=0.96:${PORTSDIR}/devel/p5-Module-ScanDeps \
		${SITE_PERL}/Module/Signature.pm:${PORTSDIR}/security/p5-Module-Signature \
		p5-PAR-Dist>=0.22:${PORTSDIR}/devel/p5-PAR-Dist \
		p5-PAR>=1.00.0:${PORTSDIR}/devel/p5-PAR \
		${SITE_PERL}/B/Deobfuscate.pm:${PORTSDIR}/devel/p5-B-Deobfuscate
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	sketchy-*

PERL_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=		par.pl.1 parl.1 pp.1 tkpp.1
MAN3=		pp.3 \
		App::Packer::PAR.3 \
		PAR::Filter.3 \
		PAR::Filter::Bleach.3 \
		PAR::Filter::Bytecode.3 \
		PAR::Filter::Obfuscate.3 \
		PAR::Filter::PatchContent.3 \
		PAR::Filter::PodStrip.3 \
		PAR::Packer.3 \
		PAR::StrippedPARL::Base.3 \
		PAR::StrippedPARL::Dynamic.3 \
		PAR::StrippedPARL::Static.3

.include <bsd.port.mk>
