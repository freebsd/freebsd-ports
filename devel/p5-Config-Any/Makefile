# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Config-Any
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Load class configuration data from a number of file formats

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Pluggable>=3.6:devel/p5-Module-Pluggable
RUN_DEPENDS=	p5-Module-Pluggable>=3.6:devel/p5-Module-Pluggable

OPTIONS_DEFINE=	GENERAL INI JSON XML YAML
OPTIONS_DEFAULT=GENERAL INI JSON XML YAML

GENERAL_DESC=	Generic Config format support

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

GENERAL_BUILD_DEPENDS=	p5-Config-General>=2.47:devel/p5-Config-General
GENERAL_RUN_DEPENDS=	p5-Config-General>=2.47:devel/p5-Config-General
INI_BUILD_DEPENDS=	p5-Config-Tiny>=0:devel/p5-Config-Tiny
INI_RUN_DEPENDS=	p5-Config-Tiny>=0:devel/p5-Config-Tiny
JSON_BUILD_DEPENDS=	p5-JSON-XS>=0:converters/p5-JSON-XS
JSON_RUN_DEPENDS=	p5-JSON-XS>=0:converters/p5-JSON-XS
XML_BUILD_DEPENDS=	p5-XML-Simple>=0:textproc/p5-XML-Simple
XML_RUN_DEPENDS=	p5-XML-Simple>=0:textproc/p5-XML-Simple
YAML_BUILD_DEPENDS=	p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML
YAML_RUN_DEPENDS=	p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML

.include <bsd.port.mk>
