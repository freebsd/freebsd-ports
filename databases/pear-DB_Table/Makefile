# Ports collection makefile for:  pear-DB_Table
# Date created:			  08 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	DB_Table
PORTVERSION=	1.0.1
CATEGORIES=	databases www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR object-oriented interface to a database table

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB \
		${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes

LATEST_LINK=	pear-DB_Table
OPTIONS=	PEAR_HTML_QUICKFORM "PEAR::HTML_QuickForm support" off

CATEGORY=	DB
FILES=		Table.php Table/Manager.php Table/QuickForm.php Table/Valid.php
DOCS=		_sources.txt all-words.txt mssql-words.txt mysql-words.txt \
		oci8-words.txt pgsql-words.txt sql92-words.txt sql99-words.txt \
		sqlite-words.txt
TESTS=		bogotest.php setup.ini-dist
_DOCSDIR=	docs/reserved_words

post-extract:
	@${MV} ${WRKSRC}/DB/* ${WRKSRC}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" \
		${WRKSRC}/Table.php

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_HTML_QUICKFORM)
RUN_DEPENDS+=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
