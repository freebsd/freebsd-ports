# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	SQL-Translator
PORTVERSION=	0.11016
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulate structured data definitions (SQL and more)

BUILD_DEPENDS=	p5-Class-Base>=0:${PORTSDIR}/devel/p5-Class-Base \
		p5-Class-Data-Inheritable>=0.02:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-MakeMethods>=0:${PORTSDIR}/devel/p5-Class-MakeMethods \
		p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-File-ShareDir>=1:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Digest-SHA1>=2.0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Parse-RecDescent>=1.962.2:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Template-Toolkit>=2.20:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Moo>=0.009007:${PORTSDIR}/devel/p5-Moo \
		p5-Package-Variant>=0:${PORTSDIR}/devel/p5-Package-Variant \
		p5-Spreadsheet-ParseExcel>=0.41:${PORTSDIR}/textproc/p5-Spreadsheet-ParseExcel \
		p5-Text-ParseWords>0:${PORTSDIR}/textproc/p5-Text-ParseWords \
		p5-Text-RecordParser>=0.02:${PORTSDIR}/textproc/p5-Text-RecordParser \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-XML-LibXML>=1.69:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Writer>=0.5:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-YAML>0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0.61:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

OPTIONS_DEFINE=	DIAGRAM
DIAGRAM_DESC=	Diagram generation support

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDIAGRAM}
BUILD_DEPENDS+= p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-Graph>=0:${PORTSDIR}/math/p5-Graph \
		p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz
.endif

.include <bsd.port.mk>
