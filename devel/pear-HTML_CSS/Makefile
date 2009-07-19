# Ports collection makefile for:  pear-HTML_CSS
# Date created:			  16 May 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTML_CSS
PORTVERSION=	1.5.4
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for generating CSS declarations

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML
FILES=		CSS.php CSS/Error.php
EXAMPLES=	CSS_Advanced.php CSS_Logger.php CSS_req12194_atrule_api.php \
		css_error_ignore.php CSS_DisplayOnline.php CSS_Stylesheet.php \
		CSS_req12194_atrule_parser.php css_error_logger.php CSS_InHeader.php \
		CSS_grepStyles.php CSS_validate.php css_errorstack_custom.php \
		CSS_Inline.php CSS_parseData.php css_error_custom.php css_errorstack_logger.php
TESTES=		AllTests.php HTML_CSS_TestSuite_Bugs.php \
		HTML_CSS_TestSuite_Standard.php stylesheet.css

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
