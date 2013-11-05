# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	SQL-Translator
PORTVERSION=	0.11018
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulate structured data definitions (SQL and more)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-DBI>=1.54:${PORTSDIR}/databases/p5-DBI \
		p5-File-ShareDir>=1:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-JSON>=2:${PORTSDIR}/converters/p5-JSON \
		p5-List-MoreUtils>=0.09:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moo>=1.000003:${PORTSDIR}/devel/p5-Moo \
		p5-Package-Variant>=1.001001:${PORTSDIR}/devel/p5-Package-Variant \
		p5-Parse-RecDescent>=1.967.009:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Spreadsheet-ParseExcel>=0.41:${PORTSDIR}/textproc/p5-Spreadsheet-ParseExcel \
		p5-Template-Toolkit>=2.20:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Text-ParseWords>=0:${PORTSDIR}/textproc/p5-Text-ParseWords \
		p5-Text-RecordParser>=0.02:${PORTSDIR}/textproc/p5-Text-RecordParser \
		p5-Try-Tiny>=0.04:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-XML-Writer>=0.5:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-XML-LibXML>=1.69:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-YAML>=0.66:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Test-Differences>=0.61:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

OPTIONS_DEFINE=	DIAGRAM
DIAGRAM_DESC=	Diagram generation support

REINPLACE_ARGS=	-i ''
USES=		perl5
USE_PERL5=	configure

DIAGRAM_BUILD_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
			p5-Graph>=0:${PORTSDIR}/math/p5-Graph \
			p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz

post-patch:
	@${REINPLACE_CMD} -e 's|@EXPORT|&_OK|' ${WRKSRC}/lib/SQL/Translator/Parser/xSV.pm

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

.include <bsd.port.mk>
