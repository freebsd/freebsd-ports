# New ports collection makefile for:	Module-Install
# Date created:				Sep 15 2004
# Whom:                			clsung
#
# $FreeBSD$
#

PORTNAME=	Module-Install
PORTVERSION=	0.91
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Standalone, extensible Perl module installer

RUN_DEPENDS=	${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/Module/ScanDeps.pm:${PORTSDIR}/devel/p5-Module-ScanDeps \
		${SITE_PERL}/Module/CoreList.pm:${PORTSDIR}/devel/p5-Module-CoreList \
		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build \
		${SITE_PERL}/PAR/Dist.pm:${PORTSDIR}/devel/p5-PAR-Dist \
		${SITE_PERL}/YAML/Tiny.pm:${PORTSDIR}/textproc/p5-YAML-Tiny \
		${SITE_PERL}/ExtUtils/ParseXS.pm:${PORTSDIR}/devel/p5-ExtUtils-ParseXS \
		${SITE_PERL}/${PERL_ARCH}/Devel/PPPort.pm:${PORTSDIR}/devel/p5-Devel-PPPort
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	--skip

MAN3=		inc::Module::Install.3 \
		inc::Module::Install::DSL.3 \
		Module::AutoInstall.3 \
		Module::Install.3 \
		Module::Install::Admin.3 \
		Module::Install::Admin::Include.3 \
		Module::Install::Admin::Manifest.3 \
		Module::Install::Base.3 \
		Module::Install::Bundle.3 \
		Module::Install::Can.3 \
		Module::Install::Compiler.3 \
		Module::Install::Deprecated.3 \
		Module::Install::External.3 \
		Module::Install::Makefile.3 \
    		Module::Install::PAR.3 \
		Module::Install::Philosophy.3 \
		Module::Install::Share.3 \
		Module::Install::With.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
BUILD_DEPENDS+=	${SITE_PERL}/Pod/Man.pm:${PORTSDIR}/textproc/p5-podlators
.endif

.include <bsd.port.post.mk>
