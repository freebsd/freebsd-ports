# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	BioPerl
PORTVERSION=	1.007005
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CDRAUG
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-1.7.4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of Perl modules for bioinformatics

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-Data-Stag>=0:devel/p5-Data-Stag \
		p5-Error>=0:lang/p5-Error \
		p5-GD>=0:graphics/p5-GD \
		p5-Graph>=0:math/p5-Graph \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-IO-stringy>=0:devel/p5-IO-stringy \
		p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Module-Build>=0:devel/p5-Module-Build \
		p5-Set-Scalar>=0:devel/p5-Set-Scalar \
		p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Test-RequiresInternet>=0:devel/p5-Test-RequiresInternet \
		p5-URI>=0:net/p5-URI \
		p5-XML-DOM-XPath>=0:textproc/p5-XML-DOM-XPath \
		p5-XML-DOM>=0:textproc/p5-XML-DOM \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-SAX-Base>=0:textproc/p5-XML-SAX-Base \
		p5-XML-SAX-Writer>=0:textproc/p5-XML-SAX-Writer \
		p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-XML-Twig>=0:textproc/p5-XML-Twig \
		p5-XML-Writer>=0:textproc/p5-XML-Writer \
		p5-YAML>=0:textproc/p5-YAML \
		p5-libwww>=0:www/p5-libwww \
		p5-libxml>=0:textproc/p5-libxml
TEST_DEPENDS=	p5-Test-Memory-Cycle>=0:devel/p5-Test-Memory-Cycle \
		p5-Test-Weaken>=0:devel/p5-Test-Weaken

USES=		perl5 shebangfix
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES PGTEST SQLITETEST
PGTEST_DESC=	Test PostGreSQL
SQLITETEST_DESC=Test SQLite

PGTEST_RUN_DEPENDS=	p5-DBD-Pg>=3:databases/p5-DBD-Pg
PGTEST_BUILD_DEPENDS=	p5-DBD-Pg>=3:databases/p5-DBD-Pg
SQLITETEST_RUN_DEPENDS=	p5-DBD-SQLite>=1:databases/p5-DBD-SQLite
SQLITETEST_BUILD_DEPENDS=	p5-DBD-SQLite>=1:databases/p5-DBD-SQLite

SHEBANG_FILES=	examples/*.pl examples/*/*.pl

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS Changes MANIFEST README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
