# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	bioperl
PORTVERSION=	1.6.923
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CJFIELDS
PKGNAMEPREFIX=	p5-
DISTNAME=	BioPerl-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Collection of Perl modules for bioinformatics

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Text-Tabs+Wrap>=0:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap \
		p5-Bio-ASN1-EntrezGene>=0:${PORTSDIR}/biology/p5-Bio-ASN1-EntrezGene \
		p5-Class-AutoClass>=0:${PORTSDIR}/devel/p5-Class-AutoClass \
		p5-Data-Stag>=0:${PORTSDIR}/devel/p5-Data-Stag \
		p5-Data-Stag>=0:${PORTSDIR}/devel/p5-Data-Stag \
		p5-Data-Stag>=0:${PORTSDIR}/devel/p5-Data-Stag \
		p5-GD-SVG>=0:${PORTSDIR}/graphics/p5-GD-SVG \
		p5-Graph>=0:${PORTSDIR}/math/p5-Graph \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-SVG>=0:${PORTSDIR}/textproc/p5-SVG \
		p5-SVG-Graph>=0:${PORTSDIR}/graphics/p5-SVG-Graph \
		p5-Text-Shellwords>=0:${PORTSDIR}/textproc/p5-Text-Shellwords \
		p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM \
		p5-XML-DOM-XPath>=0:${PORTSDIR}/textproc/p5-XML-DOM-XPath \
		p5-libxml>=0:${PORTSDIR}/textproc/p5-libxml \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-SAX-Writer>=0:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-Spreadsheet-ParseExcel>=0:${PORTSDIR}/textproc/p5-Spreadsheet-ParseExcel \
		p5-Convert-Binary-C>=0:${PORTSDIR}/converters/p5-Convert-Binary-C \
		p5-Algorithm-Munkres>=0:${PORTSDIR}/math/p5-Algorithm-Munkres \
		p5-Array-Compare>=0:${PORTSDIR}/misc/p5-Array-Compare \
		p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz \
		p5-Math-Random>=0:${PORTSDIR}/math/p5-Math-Random \
		p5-PostScript>=0:${PORTSDIR}/print/p5-PostScript \
		p5-Set-Scalar>=0:${PORTSDIR}/devel/p5-Set-Scalar \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most \
		p5-HTML-TableExtract>=2:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-Sort-Naturally>=1:${PORTSDIR}/textproc/p5-Sort-Naturally \
		p5-XML-Simple>=2:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

OPTIONS_DEFINE=	DOCS PGTEST SQLITETEST
PGTEST_DESC=	Test PostGreSQL
SQLITETEST_DESC=	Test SQLite
PGTEST_RUN_DEPENDS=	p5-DBD-Pg>=3:${PORTSDIR}/databases/p5-DBD-Pg
PGTEST_BUILD_DEPENDS=	p5-DBD-Pg>=3:${PORTSDIR}/databases/p5-DBD-Pg
SQLITETEST_RUN_DEPENDS=	p5-DBD-SQLite>=1:${PORTSDIR}/databases/p5-DBD-SQLite
SQLITETEST_BUILD_DEPENDS=	p5-DBD-SQLite>=1:${PORTSDIR}/databases/p5-DBD-SQLite

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/scripts ${WRKSRC}/models ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS BUGS Changes DEPENDENCIES DEPRECATED INSTALL LICENSE MANIFEST README
	${INSTALL_MAN} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
	${CP} -R ${WRKSRC}/doc ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
