# Created by: Alex Kapranoff <kappa@rambler-co.ru>
# $FreeBSD$

PORTNAME=	CPANPLUS
PORTVERSION=	0.9168
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Ameliorated interface to the CPAN

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Extract>=0.16:archivers/p5-Archive-Extract \
		p5-Log-Message>=0.01:devel/p5-Log-Message \
		p5-Module-Pluggable>=2.4:devel/p5-Module-Pluggable \
		p5-Module-Signature>=0.06:security/p5-Module-Signature \
		p5-Object-Accessor>=0.44:devel/p5-Object-Accessor \
		p5-Package-Constants>=0.01:devel/p5-Package-Constants \
		p5-Term-UI>=0.18:devel/p5-Term-UI
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	TEST_REPORTER YAML
TEST_REPORTER_DESC=	Send reports to cpan-testers

CONFIGURE_ARGS=	AUTOINSTALL=1
INSTALL_TARGET=	pure_install
MAKE_JOBS_UNSAFE=	yes
NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

TEST_REPORTER_BUILD_DEPENDS=	p5-Test-Reporter>=0:devel/p5-Test-Reporter
TEST_REPORTER_RUN_DEPENDS=	p5-Test-Reporter>=0:devel/p5-Test-Reporter
YAML_BUILD_DEPENDS=	p5-YAML>=0:textproc/p5-YAML
YAML_RUN_DEPENDS=	p5-YAML>=0:textproc/p5-YAML

post-patch:
	@${REINPLACE_CMD} -e '/install_script/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
