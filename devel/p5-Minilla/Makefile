# Created by: Serguei Okladnikov <oklaspec@gmail.com>
# $FreeBSD$
# Date created: 2015-05-28

PORTNAME=	Minilla
PORTVERSION=	3.0.15
DISTVERSIONPREFIX=	v
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SKAJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	oklaspec@gmail.com
COMMENT=	CPAN module authoring tool

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git>=0:devel/git \
		tree>=0:sysutils/tree \
		p5-App-cpanminus>=1.6902:devel/p5-App-cpanminus \
		p5-CPAN-Uploader>=0:devel/p5-CPAN-Uploader \
		p5-Config-Identity>=0:devel/p5-Config-Identity \
		p5-Data-Section-Simple>=0.04:devel/p5-Data-Section-Simple \
		p5-Devel-CheckBin>=0:devel/p5-Devel-CheckBin \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-File-pushd>=0:devel/p5-File-pushd \
		p5-Module-CPANfile>=0.9025:devel/p5-Module-CPANfile \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=1.001:devel/p5-Moo \
		p5-Pod-Markdown>=1.322:textproc/p5-Pod-Markdown \
		p5-Software-License>=0.103010:misc/p5-Software-License \
		p5-TOML>=0.95:textproc/p5-TOML \
		p5-Text-MicroTemplate>=0.20:textproc/p5-Text-MicroTemplate \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-URI>=0:net/p5-URI \
		p5-Version-Next>=0:textproc/p5-Version-Next
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-JSON>=0:converters/p5-JSON \
		p5-Test-Output>=0:devel/p5-Test-Output \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502400
BUILD_DEPENDS+=	p5-Module-Metadata>=1.000027:devel/p5-Module-Metadata
RUN_DEPENDS+=	p5-Module-Metadata>=1.000027:devel/p5-Module-Metadata
.endif

pre-test:
	@test ! -e ${WRKDIR}/.gitconfig && \
		${SETENV} ${MAKE_ENV} git config --global user.name "ports-test" && \
		${SETENV} ${MAKE_ENV} git config --global user.email "${USER}@${HOST}" || \
		true

.include <bsd.port.post.mk>
