# Ports collection makefile for:  pear-PHP_CompatInfo
# Date created:			  15 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PHP_CompatInfo
PORTVERSION=	1.0.0
CATEGORIES=	devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class to find out the minimum version and extensions required

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	tokenizer

CATEGORY=	PHP
FILES=		CompatInfo/Cli.php CompatInfo.php
DOCS=		media/background.png media/empty.png media/style.css \
		PHP_CompatInfo/PHP_CompatInfo.html PHP_CompatInfo/PHP_CompatInfo_Cli.html \
		PHP_CompatInfo/_CompatInfo_CompatInfo_Cli_php.html \
		PHP_CompatInfo/_CompatInfo_CompatInfo_php.html \
		PHP_CompatInfo/_CompatInfo_data_const_array_php.html \
		PHP_CompatInfo/_CompatInfo_data_func_array_php.html \
		PHP_CompatInfo/_CompatInfo_data_token_array_php.html \
		PHP_CompatInfo/_CompatInfo_docs_examples_checkConstants_php.html \
		PHP_CompatInfo/_CompatInfo_docs_examples_Cli_php.html \
		PHP_CompatInfo/_CompatInfo_docs_examples_parseArray_php.html \
		PHP_CompatInfo/_CompatInfo_docs_examples_parseDir_php.html \
		PHP_CompatInfo/_CompatInfo_docs_examples_parseFile_php.html \
		PHP_CompatInfo/_CompatInfo_docs_examples_parseString_php.html \
		PHP_CompatInfo/_CompatInfo_package_php.html \
		PHP_CompatInfo/_CompatInfo_scripts_updateVersionInfo_php.html \
		__examplesource/exsource_ar_PHP_CompatInfo_docs_examples_checkConstants.php_cb2bb84fe2e617c3585b861431bf7b91.html \
		__examplesource/exsource_cvs_pear_PHP_CompatInfo_docs_examples_parseDir.php_58b8884c168f5711b2067a637f8b9d99.html \
		__examplesource/exsource_s_pear_PHP_CompatInfo_docs_examples_parseArray.php_e8985f384f5d7ebe7d4a6377c9a484bf.html \
		__examplesource/exsource_vs_pear_PHP_CompatInfo_docs_examples_parseFile.php_0bae5aabc7473b93eabd04e4cce4a70c.html \
		__examplesource/exsource__pear_PHP_CompatInfo_docs_examples_parseString.php_8f8087f701e8c04f5b215035957e357c.html \
		__examplesource/exsource__php-cvs_pear_PHP_CompatInfo_docs_examples_Cli.php_4570e866d6e54d3b460127e2df0f2ab7.html \
		__filesource/fsource_PHP_CompatInfo__CompatInfo.php.html \
		__filesource/fsource_PHP_CompatInfo__CompatInfoCli.php.html \
		__filesource/fsource_PHP_CompatInfo__dataconst_array.php.html \
		__filesource/fsource_PHP_CompatInfo__datafunc_array.php.html \
		__filesource/fsource_PHP_CompatInfo__datatoken_array.php.html \
		__filesource/fsource_PHP_CompatInfo__docsexamplescheckConstants.php.html \
		__filesource/fsource_PHP_CompatInfo__docsexamplesCli.php.html \
		__filesource/fsource_PHP_CompatInfo__docsexamplesparseArray.php.html \
		__filesource/fsource_PHP_CompatInfo__docsexamplesparseDir.php.html \
		__filesource/fsource_PHP_CompatInfo__docsexamplesparseFile.php.html \
		__filesource/fsource_PHP_CompatInfo__docsexamplesparseString.php.html \
		__filesource/fsource_PHP_CompatInfo__package.php.html \
		__filesource/fsource_PHP_CompatInfo__scriptsupdateVersionInfo.php.html \
		classtrees_PHP_CompatInfo.html elementindex.html \
		elementindex_PHP_CompatInfo.html errors.html index.html \
		li_PHP_CompatInfo.html
EXAMPLES=	checkConstants.php Cli.php cliOutput.txt parseArray.php parseDir.php \
		parseFile.php parseString.php
DATA=		const_array.php func_array.php updateVersionInfo.php
_EXAMPLESDIR=	docs/examples

LATEST_LINK=	pear-PHP_CompatInfo
OPTIONS=	PEAR_CONSOLE_TABLE "PEAR::Console_Table support" off

post-extract:
	@${MV} ${WRKSRC}/scripts/* ${WRKSRC}/data

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_CONSOLE_TABLE)
RUN_DEPENDS+=	${PEARDIR}/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
