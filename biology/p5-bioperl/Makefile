# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	bioperl
PORTVERSION=	1.6.924
PORTREVISION=	4
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CJFIELDS
PKGNAMEPREFIX=	p5-
DISTNAME=	BioPerl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Collection of Perl modules for bioinformatics

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Algorithm-Munkres>=0:math/p5-Algorithm-Munkres \
		p5-Array-Compare>=0:misc/p5-Array-Compare \
		p5-Class-AutoClass>=0:devel/p5-Class-AutoClass \
		p5-Clone>=0:devel/p5-Clone \
		p5-Convert-Binary-C>=0:converters/p5-Convert-Binary-C \
		p5-Data-Stag>=0:devel/p5-Data-Stag \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-Error>=0:lang/p5-Error \
		p5-GD>=0:graphics/p5-GD \
		p5-GD-SVG>=0:graphics/p5-GD-SVG \
		p5-Graph>=0:math/p5-Graph \
		p5-GraphViz>=0:graphics/p5-GraphViz \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-TableExtract>=2:www/p5-HTML-TableExtract \
		p5-IO-stringy>=0:devel/p5-IO-stringy \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-Math-Random>=0:math/p5-Math-Random \
		p5-PostScript>=0:print/p5-PostScript \
		p5-SOAP-Lite>=0:net/p5-SOAP-Lite \
		p5-Set-Scalar>=0:devel/p5-Set-Scalar \
		p5-Sort-Naturally>=1:textproc/p5-Sort-Naturally \
		p5-Spreadsheet-ParseExcel>=0:textproc/p5-Spreadsheet-ParseExcel \
		p5-SVG>=0:textproc/p5-SVG \
		p5-SVG-Graph>=0:graphics/p5-SVG-Graph \
		p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Text-Shellwords>=0:textproc/p5-Text-Shellwords \
		p5-Text-Tabs+Wrap>=0:textproc/p5-Text-Tabs+Wrap \
		p5-URI>=0:net/p5-URI \
		p5-XML-DOM>=0:textproc/p5-XML-DOM \
		p5-XML-DOM-XPath>=0:textproc/p5-XML-DOM-XPath \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-XML-SAX-Writer>=0:textproc/p5-XML-SAX-Writer \
		p5-XML-Simple>=2:textproc/p5-XML-Simple \
		p5-XML-Twig>=0:textproc/p5-XML-Twig \
		p5-XML-Writer>=0:textproc/p5-XML-Writer \
		p5-YAML>=0:textproc/p5-YAML \
		p5-libwww>=0:www/p5-libwww \
		p5-libxml>=0:textproc/p5-libxml

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES PGTEST SQLITETEST
PGTEST_DESC=	Test PostGreSQL
SQLITETEST_DESC=	Test SQLite
PGTEST_RUN_DEPENDS=	p5-DBD-Pg>=3:databases/p5-DBD-Pg
PGTEST_BUILD_DEPENDS=	p5-DBD-Pg>=3:databases/p5-DBD-Pg
SQLITETEST_RUN_DEPENDS=	p5-DBD-SQLite>=1:databases/p5-DBD-SQLite
SQLITETEST_BUILD_DEPENDS=	p5-DBD-SQLite>=1:databases/p5-DBD-SQLite

post-patch:
	@${FIND} ${WRKSRC}/examples ${WRKSRC}/doc -name "*.pl" -o -name "*.cgi" \
		-o -name "*.PL" | ${XARGS} ${REINPLACE_CMD} -i '' -Ee \
		'1s|(/usr)?/bin/perl|${PERL}|'

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/scripts ${WRKSRC}/models ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS BUGS Changes DEPENDENCIES DEPRECATED INSTALL LICENSE MANIFEST README
	${INSTALL_MAN} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
	${CP} -R ${WRKSRC}/doc ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
