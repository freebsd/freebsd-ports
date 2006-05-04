# Ports collection makefile for:  pear-PHP_Beautifier
# Date created:			  13 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PHP_Beautifier
PORTVERSION=	0.1.4
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR beautifier for PHP

BUILD_DEPENDS=	${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	tokenizer

NO_PACKAGE=     Conflicting dependences between PHP4 and PHP5

DEFAULT_PHP_VER=5
BROKEN_WITH_PHP=4

CATEGORY=	PHP
FILES=		Beautifier.php Beautifier/Filter.php Beautifier/Decorator.php \
		Beautifier/Batch.php Beautifier/Common.php Beautifier/Exception.php \
		Beautifier/StreamWrapper.php Beautifier/Tokenizer.php \
		Beautifier/Filter/ArrayNested.filter.php \
		Beautifier/Filter/Default.filter.php \
		Beautifier/Filter/ListClassFunction.filter.php \
		Beautifier/Filter/Pear.filter.php \
		Beautifier/Filter/IndentStyles.filter.php \
		Beautifier/Filter/NewLines.filter.php Beautifier/Batch/Output.php \
		Beautifier/Batch/Output/Directory.php \
		Beautifier/Batch/Output/DirectoryBz2.php \
		Beautifier/Batch/Output/DirectoryGz.php \
		Beautifier/Batch/Output/DirectoryTar.php \
		Beautifier/Batch/Output/Files.php \
		Beautifier/Batch/Output/FilesBz2.php \
		Beautifier/Batch/Output/FilesGz.php \
		Beautifier/Batch/Output/FilesTar.php \
		Beautifier/StreamWrapper/Tarz.php
EXAMPLES=	run_me.php example_main.php example_pear.php example_array.php \
		example_comments.php example_html.php
TESTS=		Beautifier.phpt Beautifier_Common.phpt Beautifier_Bugs.phpt \
		Beautifier_StreamWrapper.phpt
DATA=		apache.txt bsd.txt lgpl.txt php.txt pear.txt
_DATADIR=	licenses
SCRIPTFILES=	php_beautifier

post-extract:
	@${SED} 's|"@php_bin@"|@php_bin@|g' \
		${WRKSRC}/scripts/${SCRIPTFILES} > ${WRKSRC}/pear-${SCRIPTFILES}

post-patch:
. for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|g" ${WRKSRC}/${file}
. endfor
. for file in ${TESTS}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|g" ${WRKSRC}/tests/${file}
. endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
