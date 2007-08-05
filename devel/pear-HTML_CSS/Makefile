# Ports collection makefile for:  pear-HTML_CSS
# Date created:			  16 May 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTML_CSS
PORTVERSION=	1.2.0
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for generating CSS declarations

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML
FILES=		CSS.php CSS/Error.php
DOCS=		TDG/img/admons/caution.png \
		TDG/img/admons/important.png TDG/img/admons/note.png \
		TDG/img/admons/tip.png TDG/img/admons/warning.png \
		TDG/img/created-with-docbook.png TDG/img/example.png \
		TDG/img/external-link.gif TDG/img/pearsmall.gif \
		TDG/img/rule.gif TDG/book.css TDG/ch01.html \
		TDG/ch01s02.html TDG/ch01s03.html TDG/ch02.html \
		TDG/ch03.html TDG/ch03s02.html TDG/ch04.html \
		TDG/ch04s02.html TDG/ch04s03.html TDG/ch05.html \
		TDG/ch05s02.html TDG/ch05s03.html TDG/ch05s04.html \
		TDG/ch05s05.html TDG/ch06.html TDG/ch06s02.html \
		TDG/ch06s03.html TDG/ch06s04.html TDG/ch06s05.html \
		TDG/ch06s06.html TDG/ch07.html TDG/ch07s02.html \
		TDG/ch07s03.html TDG/ch08.html \
		TDG/ch08s02.html TDG/ch08s03.html TDG/ch08s04.html \
		TDG/ch08s05.html TDG/ch08s05.html TDG/ch09.html \
		TDG/ch09s02.html TDG/ch09s03.html TDG/ch09s04.html \
		TDG/ch09s05.html TDG/ch10.html TDG/ch10s02.html \
		TDG/index.html TDG/pr01.html TDG/pr01s02.html \
		TDG/pt01.html TDG/pt02.html TDG/pt03.html \
		TDG/pt04.html TDG/re01.html TDG/re02.html TDG/re03.html \
		TDG/re04.html TDG/re05.html TDG/re06.html TDG/re07.html \
		TDG/re08.html TDG/re09.html TDG/re10.html TDG/re11.html \
		TDG/re12.html TDG/re13.html TDG/re14.html TDG/re15.html \
		TDG/re16.html TDG/re17.html TDG/re18.html TDG/re19.html \
		TDG/re20.html TDG/re21.html TDG/re22.html TDG/re23.html \
		TDG/re24.html
EXAMPLES=	CSS_InHeader.php css_error_custom.php \
		CSS_Inline.php css_error_ignore.php \
		CSS_Logger.php css_error_logger.php \
		CSS_Stylesheet.php css_errorstack_custom.php \
		CSS_parseData.php css_errorstack_logger.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
