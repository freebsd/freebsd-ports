# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Dist-Joseki
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Tools for the prolific module author

RUN_DEPENDS=	p5-App-Cmd>=0:${PORTSDIR}/devel/p5-App-Cmd \
		p5-Class-Accessor-Complex>=0:${PORTSDIR}/devel/p5-Class-Accessor-Complex \
		p5-Data-Rmap>=0:${PORTSDIR}/devel/p5-Data-Rmap \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Getopt-Attribute>=0:${PORTSDIR}/devel/p5-Getopt-Attribute \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

MAN1=		distfind.1
MAN3=		Dist::Joseki.3 \
		Dist::Joseki::Base.3 \
		Dist::Joseki::Cmd.3 \
		Dist::Joseki::Cmd::Command.3 \
		Dist::Joseki::Cmd::Multiplexable.3 \
		Dist::Joseki::Command::clean.3 \
		Dist::Joseki::Command::install.3 \
		Dist::Joseki::Command::manifest.3 \
		Dist::Joseki::Command::props.3 \
		Dist::Joseki::Command::test.3 \
		Dist::Joseki::Command::version.3 \
		Dist::Joseki::DistType.3 \
		Dist::Joseki::DistType::Base.3 \
		Dist::Joseki::DistType::MakeMaker.3 \
		Dist::Joseki::DistType::ModuleBuild.3 \
		Dist::Joseki::Find.3 \
		Dist::Joseki::Version.3

NO_STAGE=	yes
.include <bsd.port.mk>
