# New ports collection makefile for:	Module-Install
# Date created:				Sep 15 2004
# Whom:                			clsung
#
# $FreeBSD$
#

PORTNAME=	Module-Install
PORTVERSION=	0.62
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Standalone, extensible Perl module installer

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Module/ScanDeps.pm:${PORTSDIR}/devel/p5-Module-ScanDeps \
		${SITE_PERL}/Module/CoreList.pm:${PORTSDIR}/devel/p5-Module-CoreList \
		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build \
		${SITE_PERL}/PAR/Dist.pm:${PORTSDIR}/devel/p5-PAR-Dist \
		${SITE_PERL}/ExtUtils/ParseXS.pm:${PORTSDIR}/devel/p5-ExtUtils-ParseXS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	--skip

MAN3=		inc::Module::Install.3 \
		Module::AutoInstall.3 \
		Module::Install.3 \
		Module::Install::Admin.3 \
		Module::Install::Admin::Manifest.3 \
		Module::Install::Base.3 \
		Module::Install::Bundle.3 \
		Module::Install::Build.3 \
		Module::Install::Can.3 \
		Module::Install::Compiler.3 \
		Module::Install::Deprecated.3 \
		Module::Install::External.3 \
		Module::Install::Makefile.3 \
		Module::Install::Philosophy.3 \
		Module::Install::Share.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.x or later. Install lang/perl5 then try again
.endif
.if ${PERL_LEVEL} < 500805
BUILD_DEPENDS+=	${SITE_PERL}/Pod/Man.pm:${PORTSDIR}/textproc/p5-podlators
.endif

.include <bsd.port.post.mk>
