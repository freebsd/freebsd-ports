# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Config-Auto
PORTVERSION=	0.42
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Magical config file parser

BUILD_DEPENDS=	p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-YAML>=0.67:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	XMLSIMPLE
XMLSIMPLE_DESC=	Support for XML config files

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXMLSIMPLE}
BUILD_DEPENDS+=	p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS+=	p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
.endif

MAN3=		Config::Auto.3

.include <bsd.port.mk>
