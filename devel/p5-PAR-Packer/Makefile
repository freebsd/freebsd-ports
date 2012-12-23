# New ports collection makefile for:	devel/p5-PAR-Packer
# Date created:				Dec 06 2006
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PAR-Packer
PORTVERSION=	1.01.4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9])$/\1/}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	PAR Packager

RUN_DEPENDS=	p5-Archive-Zip>=1.00:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress \
		p5-Getopt-ArgvFile>=1.07:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-Module-ScanDeps>=1.09:${PORTSDIR}/devel/p5-Module-ScanDeps \
		p5-Module-Signature>=0:${PORTSDIR}/security/p5-Module-Signature \
		p5-PAR-Dist>=0.22:${PORTSDIR}/devel/p5-PAR-Dist \
		p5-PAR>=1.00.5:${PORTSDIR}/devel/p5-PAR \
		p5-B-Deobfuscate>=0:${PORTSDIR}/devel/p5-B-Deobfuscate
BUILD_DEPENDS:=	${RUN_DEPENDS}

CONFLICTS=	sketchy-*

PERL_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=		par.pl.1 parl.1 pp.1 tkpp.1
MAN3=		pp.3 \
		App::Packer::PAR.3 \
		Dynamic.3 \
		PAR::Filter.3 \
		PAR::Filter::Bleach.3 \
		PAR::Filter::Bytecode.3 \
		PAR::Filter::Obfuscate.3 \
		PAR::Filter::PatchContent.3 \
		PAR::Filter::PodStrip.3 \
		PAR::Packer.3 \
		PAR::StrippedPARL::Base.3 \
		Static.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
