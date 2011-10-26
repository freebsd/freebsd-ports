# New ports collection makefile for:	Module-Install
# Date created:				Sep 15 2004
# Whom:                			clsung
#
# $FreeBSD$
#

PORTNAME=	Module-Install
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Standalone, extensible Perl module installer

BUILD_DEPENDS=	p5-File-Remove>=1.42:${PORTSDIR}/devel/p5-File-Remove \
		p5-JSON>=2.14:${PORTSDIR}/converters/p5-JSON \
		p5-Module-ScanDeps>=0.89:${PORTSDIR}/devel/p5-Module-ScanDeps \
		p5-PAR-Dist>=0.29:${PORTSDIR}/devel/p5-PAR-Dist \
		p5-YAML-Tiny>=1.38:${PORTSDIR}/textproc/p5-YAML-Tiny \
		p5-libwww>=5.812:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	--skip

MAN3=		inc::Module::Install.3 \
		inc::Module::Install::DSL.3 \
		Module::AutoInstall.3 \
		Module::Install.3 \
		Module::Install::Admin.3 \
		Module::Install::API.3 \
		Module::Install::Admin::Include.3 \
		Module::Install::Admin::Manifest.3 \
		Module::Install::Base.3 \
		Module::Install::Bundle.3 \
		Module::Install::Can.3 \
		Module::Install::Compiler.3 \
		Module::Install::Deprecated.3 \
		Module::Install::External.3 \
		Module::Install::FAQ.3 \
		Module::Install::Makefile.3 \
		Module::Install::PAR.3 \
		Module::Install::Philosophy.3 \
		Module::Install::Share.3 \
		Module::Install::With.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} == 501000
BUILD_DEPENDS+=	p5-Module-CoreList>=2.17:${PORTSDIR}/devel/p5-Module-CoreList
RUN_DEPENDS+=	p5-Module-CoreList>=2.17:${PORTSDIR}/devel/p5-Module-CoreList
.endif

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Archive-Tar>=1.44:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-Devel-PPPort>=3.16:${PORTSDIR}/devel/p5-Devel-PPPort \
		p5-Module-Build>=0.29:${PORTSDIR}/devel/p5-Module-Build \
		p5-Parse-CPAN-Meta>=1.39:${PORTSDIR}/devel/p5-Parse-CPAN-Meta
RUN_DEPENDS+=	p5-Archive-Tar>=1.44:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-Devel-PPPort>=3.16:${PORTSDIR}/devel/p5-Devel-PPPort \
		p5-Module-Build>=0.29:${PORTSDIR}/devel/p5-Module-Build \
		p5-Parse-CPAN-Meta>=1.39:${PORTSDIR}/devel/p5-Parse-CPAN-Meta
.endif

.include <bsd.port.post.mk>
