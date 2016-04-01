# Created by: Serguei Okladnikov <oklaspec@gmail.com>
# $FreeBSD$
# Date created: 2015-05-28

PORTNAME=	Minilla
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	oklaspec@gmail.com
COMMENT=	CPAN module authoring tool

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	git>=0:devel/git \
		tree>=0:sysutils/tree \
		p5-App-cpanminus>=1.6902:devel/p5-App-cpanminus \
		p5-Archive-Tar>=1.60:archivers/p5-Archive-Tar \
		p5-CPAN-Meta>=2.132830:devel/p5-CPAN-Meta \
		p5-Config-Identity>=0:devel/p5-Config-Identity \
		p5-Data-Section-Simple>=0.04:devel/p5-Data-Section-Simple \
		p5-ExtUtils-Manifest>=1.54:devel/p5-ExtUtils-Manifest \
		p5-CPAN-Uploader>=0:devel/p5-CPAN-Uploader \
		p5-Class-XSAccessor>=0:devel/p5-Class-XSAccessor \
		p5-Config-Identity>=0:devel/p5-Config-Identity \
		p5-Devel-CheckBin>=0:devel/p5-Devel-CheckBin \
		p5-Devel-GlobalDestruction>=0:devel/p5-Devel-GlobalDestruction \
		p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-File-pushd>=0:devel/p5-File-pushd \
		p5-Getopt-Long>=2.36:devel/p5-Getopt-Long \
		p5-JSON>=0:converters/p5-JSON \
		p5-Module-Build-Tiny>=0:devel/p5-Module-Build-Tiny \
		p5-Module-CPANfile>=0.9025:devel/p5-Module-CPANfile \
		p5-Module-Metadata>=1.000012:devel/p5-Module-Metadata \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=1.001:devel/p5-Moo \
		p5-Pod-Markdown>=1.322:textproc/p5-Pod-Markdown \
		p5-TOML>=0:textproc/p5-TOML \
		p5-Term-ANSIColor>=0:devel/p5-Term-ANSIColor \
		p5-Text-MicroTemplate>=0.20:textproc/p5-Text-MicroTemplate \
		p5-Time-Piece>=1.16:devel/p5-Time-Piece \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-Test-Output>=0:devel/p5-Test-Output \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-Harness>=0:devel/p5-Test-Harness \
		p5-strictures>=0:devel/p5-strictures \
		p5-Software-License>=0:misc/p5-Software-License \
		p5-Version-Next>=0:textproc/p5-Version-Next
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

regression-test: build
	@test ! -e ${WRKDIR}/.gitconfig && \
		${SETENV} ${MAKE_ENV} git config --global user.name "ports-test" && \
		${SETENV} ${MAKE_ENV} git config --global user.email "${USER}@${HOST}" || \
		true
	@cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${PERL5} ${PL_BUILD} ${MAKE_ARGS} test

.include <bsd.port.mk>
