# $FreeBSD$

PORTNAME=	Exporter-Declare
PORTVERSION=	0.113
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for exporting done right

RUN_DEPENDS=	\
	p5-Meta-Builder>=0.003:${PORTSDIR}/devel/p5-Meta-Builder \
	p5-aliased>0:${PORTSDIR}/devel/p5-aliased
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Fennec-Lite>=0:${PORTSDIR}/devel/p5-Fennec-Lite \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=	perl5
USE_PERL5=	modbuild

MAN3=	Exporter::Declare.3 \
	Exporter::Declare::Export.3 \
	Exporter::Declare::Export::Alias.3 \
	Exporter::Declare::Export::Generator.3 \
	Exporter::Declare::Export::Sub.3 \
	Exporter::Declare::Export::Variable.3 \
	Exporter::Declare::Meta.3 \
	Exporter::Declare::Specs.3

NO_STAGE=	yes
.include <bsd.port.mk>
