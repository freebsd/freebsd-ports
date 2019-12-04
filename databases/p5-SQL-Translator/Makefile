# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	SQL-Translator
PORTVERSION=	1.60
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulate structured data definitions (SQL and more)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-File-ShareDir-Install>=0:devel/p5-File-ShareDir-Install
RUN_DEPENDS=	p5-Carp-Clan>=0:devel/p5-Carp-Clan \
		p5-DBI>=1.54:databases/p5-DBI \
		p5-File-ShareDir>=1:devel/p5-File-ShareDir \
		p5-JSON-MaybeXS>=1.003003:converters/p5-JSON-MaybeXS \
		p5-Moo>=1.000003:devel/p5-Moo \
		p5-Package-Variant>=1.001001:devel/p5-Package-Variant \
		p5-Parse-RecDescent>=1.967009:devel/p5-Parse-RecDescent \
		p5-Spreadsheet-ParseExcel>=0.41:textproc/p5-Spreadsheet-ParseExcel \
		p5-Sub-Quote>=0:devel/p5-Sub-Quote \
		p5-Template-Toolkit>=2.20:www/p5-Template-Toolkit \
		p5-Text-RecordParser>=0.02:textproc/p5-Text-RecordParser \
		p5-Try-Tiny>=0.04:lang/p5-Try-Tiny \
		p5-XML-LibXML>=1.69:textproc/p5-XML-LibXML \
		p5-XML-Writer>=0.500:textproc/p5-XML-Writer \
		p5-YAML>=0.66:textproc/p5-YAML
TEST_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Exception>=0.31:devel/p5-Test-Exception

USES=		perl5

OPTIONS_DEFINE=		DIAGRAM
DIAGRAM_DESC=		Diagram generation support
USE_PERL5=		configure
NO_ARCH=		yes
DIAGRAM_BUILD_DEPENDS=	${DIAGRAM_RUN_DEPENDS}
DIAGRAM_RUN_DEPENDS=	p5-GD>=0:graphics/p5-GD \
			p5-Graph>=0:math/p5-Graph \
			p5-GraphViz>=0:graphics/p5-GraphViz

.include <bsd.port.mk>
