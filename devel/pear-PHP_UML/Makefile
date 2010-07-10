# Ports collection makefile for:  pear-PHP_UML
# Date created:			  23 May 2008
# Whom:				  Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	PHP_UML
PORTVERSION=	1.5.2
CATEGORIES=	devel

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PEAR Class to Create UML Representation of PHP Code

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Console/CommandLine.php:${PORTSDIR}/devel/pear-Console_CommandLine
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

DEFAULT_PHP_VER=	5
USE_PHP=		spl

CATEGORY=	PHP
FILES=		UML.php \
		UML/Exception.php UML/FilePatternFilterIterator.php \
		UML/FileScanner.php UML/FileScannerImpl.php \
		UML/SimpleUID.php UML/Warning.php \
		UML/Metamodel/Class.php UML/Metamodel/Enumeration.php \
		UML/Metamodel/Classifier.php UML/Metamodel/Interface.php \
		UML/Metamodel/NamedElement.php UML/Metamodel/Operation.php \
		UML/Metamodel/Package.php UML/Metamodel/Parameter.php \
		UML/Metamodel/Property.php UML/Metamodel/Stereotype.php \
		UML/Metamodel/Superstructure.php UML/Metamodel/Tag.php \
		UML/Metamodel/Type.php UML/Metamodel/TypedElement.php \
		UML/Output/common.xsl UML/Output/Exporter.php \
		UML/Output/html/allclasses-frame.xsl UML/Output/html/classifier.xsl \
		UML/Output/html/documentation-common.xsl UML/Output/html/documentation-generator.xsl \
		UML/Output/html/index-all.xsl UML/Output/html/index.xsl \
		UML/Output/html/main.xsl UML/Output/html/overview-frame.xsl \
		UML/Output/html/overview-summary.xsl UML/Output/html/package-frame.xsl \
		UML/Output/html/package-summary.xsl UML/Output/html/resources/inherit.gif \
		UML/Output/html/resources/style.css UML/Output/php/classifier.xsl \
		UML/Output/php/code-common.xsl UML/Output/php/code-generator.xsl \
		UML/Output/php/main.xsl UML/Output/xmi1to2.xsl\
		UML/PHP/Parser.php \
		UML/XMI/AbstractBuilder.php UML/XMI/Builder.php \
		UML/XMI/BuilderImpl1.php UML/XMI/BuilderImpl2.php
DOCS=		LOGICIELS_A_UTILISER_AVEC_PHP_UML \
		PHP_UML_class_diagram.png \
		PHP_UML_metamodel_class_diagram.png \
		PHP_UML_superstructure_class_diagram.png \
		README SOFTWARES_TO_USE_WITH_PHP_UML \
		TODO argouml.png bouml.png rational_rose.png readme.html
EXAMPLES=	PHP_UML_by_PHP_UML_v1.xmi PHP_UML_by_PHP_UML_v2.xmi \
		example1_rational_rose.png example2_bouml.png \
		example3_argouml.png example4_in_Bouml.png \
		test1.php.txt test2.php.txt \
		test3.php.txt test4.php.txt test5_cs.php.txt \
		test_to_run.php test_with_api.php
TESTS=		UmlParserTest.php UmlXmiTest.php \
		suite/EMOF_test_sample.php suite/PHP_UML_test_sample.php \
		suite/PHP_test_sample.php suite/bug-489398.php \
		suite/bug-540341.php suite/bug-540368.php \
		suite/bug-541886.php suite/bug-542586.php \
		suite/bug-548331.php suite/bug-550489.php \
		suite/bug-553138.php suite/bug-553560.php \
		suite/bug-553607.php suite/bug-555768.php \
		suite/bug-556031-01.php suite/bug-556031.php \
		suite/bug-556860.php suite/bug-556894.php \
		suite/bug-557390.php suite/bug-557861.php \
		suite/bug-558051.php suite/bug-559494.php \
		suite/bug-561101.php suite/bug-562997.php \
		suite/bug-566600.php suite/bug-567059.php \
		suite/bug-587733.php suite/bug-772441.php \
		suite/bug-escaping.php suite/bug-loseprocedural.php \
		suite/bug-loseunknowntags.php suite/test1.php \
		suite/test2.php suite/test3.php \
		suite/test4.php suite/test5_cs.php \
		suite/test_internal.php \
		suite/test_namespace1.php \
		suite/test_namespace2.php \
		suite/test_namespace3.php \
		suite/test_only_api.php \
		suite/data-providers/EMOF_test_sample.php.obj \
		suite/data-providers/PHP_UML_test_sample.php.obj \
		suite/data-providers/PHP_test_sample.php.obj \
		suite/data-providers/bug-489398.php.obj \
		suite/data-providers/bug-540341.php.obj \
		suite/data-providers/bug-540368.php.obj \
		suite/data-providers/bug-541886.php.obj \
		suite/data-providers/bug-542586.php.obj \
		suite/data-providers/bug-548331.php.obj \
		suite/data-providers/bug-550489.php.obj \
		suite/data-providers/bug-553138.php.obj \
		suite/data-providers/bug-553560.php.obj \
		suite/data-providers/bug-553607.php.obj \
		suite/data-providers/bug-555768.php.obj \
		suite/data-providers/bug-556031-01.php.obj \
		suite/data-providers/bug-556031.php.obj \
		suite/data-providers/bug-556860.php.obj \
		suite/data-providers/bug-556894.php.obj \
		suite/data-providers/bug-557390.php.obj \
		suite/data-providers/bug-557861.php.obj \
		suite/data-providers/bug-558051.php.obj \
		suite/data-providers/bug-559494.php.obj \
		suite/data-providers/bug-561101.php.obj \
		suite/data-providers/bug-562997.php.obj \
		suite/data-providers/bug-566600.php.obj \
		suite/data-providers/bug-567059.php.obj \
		suite/data-providers/bug-587733.php.obj \
		suite/data-providers/bug-772441.php.obj \
		suite/data-providers/bug-escaping.php.obj \
		suite/data-providers/bug-loseprocedural.php.obj \
		suite/data-providers/bug-loseunknowntags.php.obj \
		suite/data-providers/global.obj \
		suite/data-providers/global1.xmi \
		suite/data-providers/global2.xmi \
		suite/data-providers/test1.php.obj \
		suite/data-providers/test2.php.obj \
		suite/data-providers/test3.php.obj \
		suite/data-providers/test4.php.obj \
		suite/data-providers/test5_cs.php.obj \
		suite/data-providers/test_internal.php.obj \
		suite/data-providers/test_namespace1.php.obj \
		suite/data-providers/test_namespace2.php.obj \
		suite/data-providers/test_namespace3.php.obj \
		suite/data-providers/test_only_api.php.obj

DATA=		phpuml.xml

SCRIPTFILES=	phpuml

post-extract:
		@${MV} ${WRKSRC}/scripts/phpuml ${WRKSRC}/pear-phpuml

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
