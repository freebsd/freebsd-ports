# Ports collection makefile for:  pear-PHP_CompatInfo
# Date created:			  15 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PHP_CompatInfo
PORTVERSION=	1.9.0
CATEGORIES=	devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class to find out the minimum version and extensions required

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table \
		${PEARDIR}/Console/Getargs.php:${PORTSDIR}/devel/pear-Console_Getargs \
		${PEARDIR}/File/Find.php:${PORTSDIR}/sysutils/pear-File_Find \
		${PEARDIR}/Event/Dispatcher.php:${PORTSDIR}/devel/pear-Event_Dispatcher

PORTSCOUT=	skipv:1.9.0a1,1.9.0b1,1.9.0b2
USE_PHP=	tokenizer
USE_DOS2UNIX=	yes

CATEGORY=	PHP

FILES=		CompatInfo.php \
		CompatInfo/Cli.php CompatInfo/PDO_class_array.php \
		CompatInfo/PDO_func_array.php CompatInfo/Parser.php \
		CompatInfo/Reflection_class_array.php CompatInfo/Renderer.php \
		CompatInfo/SPL_class_array.php CompatInfo/SPL_func_array.php \
		CompatInfo/SQLite_class_array.php CompatInfo/SQLite_const_array.php \
		CompatInfo/SQLite_func_array.php CompatInfo/SimpleXML_class_array.php \
		CompatInfo/SimpleXML_func_array.php CompatInfo/apache2handler_sapi_array.php \
		CompatInfo/bcmath_func_array.php CompatInfo/bz2_func_array.php \
		CompatInfo/calendar_const_array.php CompatInfo/calendar_func_array.php \
		CompatInfo/cgi_sapi_array.php CompatInfo/class_array.php \
		CompatInfo/cli_sapi_array.php CompatInfo/com_dotnet_class_array.php \
		CompatInfo/com_dotnet_const_array.php CompatInfo/com_dotnet_func_array.php \
		CompatInfo/const_array.php CompatInfo/ctype_func_array.php \
		CompatInfo/date_class_array.php CompatInfo/date_const_array.php \
		CompatInfo/date_func_array.php CompatInfo/dom_class_array.php \
		CompatInfo/dom_const_array.php CompatInfo/dom_func_array.php \
		CompatInfo/filter_const_array.php CompatInfo/filter_func_array.php \
		CompatInfo/ftp_const_array.php CompatInfo/ftp_func_array.php \
		CompatInfo/func_array.php CompatInfo/gd_const_array.php \
		CompatInfo/gd_func_array.php CompatInfo/gettext_func_array.php \
		CompatInfo/gmp_const_array.php CompatInfo/gmp_func_array.php \
		CompatInfo/hash_const_array.php CompatInfo/hash_func_array.php \
		CompatInfo/iconv_const_array.php CompatInfo/iconv_func_array.php \
		CompatInfo/imap_const_array.php CompatInfo/imap_func_array.php \
		CompatInfo/internal_const_array.php CompatInfo/json_func_array.php \
		CompatInfo/libxml_class_array.php CompatInfo/libxml_const_array.php \
		CompatInfo/libxml_func_array.php CompatInfo/mbstring_const_array.php \
		CompatInfo/mbstring_func_array.php CompatInfo/ming_class_array.php \
		CompatInfo/ming_const_array.php CompatInfo/ming_func_array.php \
		CompatInfo/mysql_const_array.php CompatInfo/mysql_func_array.php \
		CompatInfo/mysqli_class_array.php CompatInfo/mysqli_const_array.php \
		CompatInfo/mysqli_func_array.php CompatInfo/odbc_const_array.php \
		CompatInfo/odbc_func_array.php CompatInfo/openssl_const_array.php \
		CompatInfo/openssl_func_array.php CompatInfo/pcre_const_array.php \
		CompatInfo/pcre_func_array.php CompatInfo/pgsql_const_array.php \
		CompatInfo/pgsql_func_array.php CompatInfo/sapi_array.php \
		CompatInfo/session_func_array.php CompatInfo/snmp_const_array.php \
		CompatInfo/snmp_func_array.php CompatInfo/standard_class_array.php \
		CompatInfo/standard_const_array.php CompatInfo/standard_func_array.php \
		CompatInfo/tokenizer_const_array.php CompatInfo/tokenizer_func_array.php \
		CompatInfo/wddx_func_array.php CompatInfo/xdebug_const_array.php \
		CompatInfo/xdebug_func_array.php CompatInfo/xml_const_array.php \
		CompatInfo/xml_func_array.php CompatInfo/xmlreader_class_array.php \
		CompatInfo/xmlwriter_class_array.php CompatInfo/xmlwriter_func_array.php \
		CompatInfo/xsl_class_array.php CompatInfo/xsl_const_array.php \
		CompatInfo/zip_class_array.php CompatInfo/zip_func_array.php \
		CompatInfo/zlib_const_array.php CompatInfo/zlib_func_array.php \
		CompatInfo/Renderer/Array.php CompatInfo/Renderer/Csv.php \
		CompatInfo/Renderer/Html.php CompatInfo/Renderer/Null.php \
		CompatInfo/Renderer/Text.php CompatInfo/Renderer/Xml.php \
		scripts/calendar_const_exceptions.php scripts/calendar_func_exceptions.php \
		scripts/class_exceptions.php scripts/compatinfo.bat \
		scripts/configure.php scripts/constant_exceptions.php \
		scripts/date_class_exceptions.php scripts/date_const_exceptions.php \
		scripts/date_func_exceptions.php scripts/exceptions.conf.php \
		scripts/ftp_const_exceptions.php scripts/function_exceptions.php \
		scripts/gd_const_exceptions.php scripts/gd_func_exceptions.php \
		scripts/gettext_func_exceptions.php scripts/gmp_const_exceptions.php \
		scripts/hash_func_exceptions.php scripts/iconv_const_exceptions.php \
		scripts/iconv_func_exceptions.php scripts/internal_const_exceptions.php \
		scripts/libxml_func_exceptions.php scripts/mysql_const_exceptions.php \
		scripts/mysqli_const_exceptions.php scripts/openssl_const_exceptions.php \
		scripts/pci.php scripts/pciconf.bat \
		scripts/pcre_const_exceptions.php scripts/spl_func_exceptions.php \
		scripts/standard_class_exceptions.php scripts/standard_const_exceptions.php \
		scripts/standard_func_exceptions.php scripts/xmlwriter_func_exceptions.php \
		scripts/xsl_const_exceptions.php scripts/zlib_func_exceptions.php

EXAMPLES=	checkConstants.php checkExtensions.php \
		checkPHP5.php ci_frontend.php \
		cliCustom.php cliOutput.txt \
		ignorePHP5implements.php parseArray.php \
		parseDir.php parseDir_withCustomProgressBar.php \
		parseFile.php parseString.php \
		pci180_loadversion.php pci180_parsearray_files.php \
		pci180_parsearray_strings.php pci180_parsedata_toxml.php \
		pci180_parsedir_tohtml.php pci180_parsefile.php \
		pci180_parsefolder.php pci180_parsefolder_tohtml.php \
		pci180_parsestring.php pci180_parsestring_toxml.php \
		yoursite.css

TESTS=		AllTests.php PHP_CompatInfo_TestSuite_Bugs.php \
		PHP_CompatInfo_TestSuite_Cli.php PHP_CompatInfo_TestSuite_Standard.php \
		beehiveforum082/forum/include/forum.inc.php checkMax.php \
		emptyDir/empty_dir.txt kohana22/modules/gmaps/javascript.php \
		parseDir/PHP5/tokens.php5 parseDir/PHP5/upload_error.php \
		parseDir/extensions.php parseDir/phpinfo.php \
		parseFile/File_Find-1.3.0__Find.php parseFile/PackageUpdate.php \
		parseFile/conditional.php parseFile/empty.php \
		parseFile/ignore_functions_match.php parseFile/math.php \
		parseFile/php5_method_chaining.php parseFile/php5_method_chaining_samp2.php \
		parseFile/phpweb-entities.php parseFile/zip.php \
		sample_req6056.php

DATA=		apache/versions.xml apc/versions.xml \
		apd/versions.xml bcmath/versions.xml \
		bzip2/versions.xml com/versions.xml \
		ctype/versions.xml datetime/versions.xml \
		dom/versions.xml filter/versions.xml \
		ftp/versions.xml gmp/versions.xml \
		hash/versions.xml iconv/versions.xml \
		image/versions.xml json/versions.xml \
		mbstring/versions.xml mysql/versions.xml \
		mysqli/versions.xml openssl/versions.xml \
		pcre/versions.xml pdo/versions.xml \
		pgsql/versions.xml posix/versions.xml \
		session/versions.xml simplexml/versions.xml \
		spl/versions.xml ssh2/versions.xml \
		tidy/versions.xml wddx/versions.xml \
		xml/versions.xml xmlreader/versions.xml \
		xmlwriter/versions.xml xsl/versions.xml \
		xslt/versions.xml zip/versions.xml \
		zlib/versions.xml

_EXAMPLESDIR=	docs/examples
_DATADIR=	data/phpdocref

LATEST_LINK=	pear-PHP_CompatInfo
OPTIONS=	PEAR_XML_BEAUTIFIER "PEAR::XML_Beautifier support" off \
		PEAR_VAR_DUMP "PEAR::Var_Dump support" off \
		PEAR_PHPUNIT "PEAR::PHPUnit support" on \
		PEAR_XML_UTIL "PEAR::XML_Util support" on \
		PEAR_HTML_TABLE "PEAR::HTML_Table" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_XML_BEAUTIFIER)
RUN_DEPENDS+=	${PEARDIR}/XML/Beautifier.php:${PORTSDIR}/textproc/pear-XML_Beautifier
.endif

.if defined(WITH_PEAR_VAR_DUMP)
RUN_DEPENDS+=	${PEARDIR}/Var/Dump.php:${PORTSDIR}/devel/pear-Var_Dump
.endif

.if defined(WITH_PEAR_PHPUNIT)
RUN_DEPENDS+=	${PEARDIR}/PHPUnit/Framework.php:${PORTSDIR}/devel/pear-PHPUnit3
.endif

.if defined(WITH_PEAR_XML_UTIL)
RUN_DEPENDS+=	${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
.endif

.if defined(WITH_PEAR_HTML_TABLE)
RUN_DEPENDS+=${PEARDIR}/HTML/Table.php:${PORTSDIR}/devel/pear-HTML_Table
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
