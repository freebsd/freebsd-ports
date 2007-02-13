# Ports collection makefile for:  pear-PHP_CompatInfo
# Date created:			  15 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PHP_CompatInfo
PORTVERSION=	1.4.1
CATEGORIES=	devel pear

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	PEAR class to find out the minimum version and extensions required

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	tokenizer

CATEGORY=	PHP
FILES=		CompatInfo/Cli.php CompatInfo/const_array.php \
		CompatInfo/func_array.php CompatInfo/pcicmd.php CompatInfo.php
DOCS=		TDG/img/admons/caution.png TDG/img/admons/important.png \
		TDG/img/admons/note.png TDG/img/admons/tip.png \
		TDG/img/admons/warning.png TDG/img/created-with-docbook.png \
		TDG/img/external-link.gif TDG/img/pearsmall.gif TDG/book.css \
		TDG/ch01.html TDG/ch01s02.html TDG/ch01s03.html TDG/ch02.html \
		TDG/ch03.html TDG/ch03s02.html TDG/ch04.html TDG/ch04s02.html \
		TDG/ch05.html TDG/ch05s02.html TDG/ch06.html TDG/ch06s02.html \
		TDG/ch07.html TDG/index.html TDG/pr01.html TDG/pr01s02.html \
		TDG/pt01.html TDG/pt02.html TDG/pt03.html TDG/re01.html \
		TDG/re02.html TDG/re03.html TDG/re04.html TDG/re05.html
EXAMPLES=	checkConstants.php checkPHP5.php ci_frontend.php cliCustom.php \
		cliOutput.txt ignorePHP5implements.php \
		parseArray.php parseDir.php parseFile.php \
		parseString.php
TESTS=		checkMax.php sample_req6056.php
_EXAMPLESDIR=	docs/examples

LATEST_LINK=	pear-PHP_CompatInfo
OPTIONS=	PEAR_CONSOLE_TABLE "PEAR::Console_Table support" off \
		PEAR_CONSOLE_GETARGS "PEAR::Console_Getargs support" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_CONSOLE_TABLE)
RUN_DEPENDS+=	${PEARDIR}/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table
.endif

.if defined(WITH_PEAR_CONSOLE_GETARGS)
RUN_DEPENDS+=	${PEARDIR}/Console/Console_TestListener.php:${PORTSDIR}/devel/pear-Console_Getargs
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
