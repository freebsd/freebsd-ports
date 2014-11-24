# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	MooseX-App-Cmd
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mashes up MooseX::Getopt and App::Cmd

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-App-Cmd>=0.321:${PORTSDIR}/devel/p5-App-Cmd \
		p5-Getopt-Long-Descriptive>=0:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-MouseX-Getopt>=0:${PORTSDIR}/devel/p5-MouseX-Getopt \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-ConfigFromFile>=0:${PORTSDIR}/devel/p5-MooseX-ConfigFromFile \
		p5-MooseX-Getopt>=0:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MouseX-ConfigFromFile>=0:${PORTSDIR}/devel/p5-MouseX-ConfigFromFile \
		p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

# Don't conflict with devel/p5-MouseX-App-Cmd
post-install:
	${RM} \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/MouseX/App/Cmd.pm \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/MouseX/App/Cmd/Command.pm \
		${STAGEDIR}${PREFIX}/${SITE_MAN3_REL}/MouseX::App::Cmd.3 \
		${STAGEDIR}${PREFIX}/${SITE_MAN3_REL}/MouseX::App::Cmd::Command.3
	${RMDIR} -p ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/MouseX/App/Cmd 2>/dev/null || :

.include <bsd.port.mk>
