# Ports collection makefile for:	pear-HTML_QuickForm_advmultiselect
# Date created:				11 November 2005
# Whom:					Chris St Denis <chris@ctgameinfo.com>
#
# $FreeBSD$
#

PORTNAME=	HTML_QuickForm_advmultiselect
PORTVERSION=	1.4.1
CATEGORIES=	devel www pear
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	chris@ctgameinfo.com
COMMENT=	Element for PEAR::HTML_QuickForm that defines a 2 box multi-select

BUILD_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm \
		${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML/QuickForm
FILES=		advmultiselect.php qfamsHandler.js
DOCS=		TDG/blank.gif TDG/ch03s04.html \
		TDG/ch06s05.html TDG/ch09s06.html \
		TDG/pt03.html TDG/book.css \
		TDG/ch03s05.html TDG/ch07.html \
		TDG/ch09s07.html TDG/pt04.html \
		TDG/ch01.html TDG/ch04.html \
		TDG/ch08.html TDG/re01.html \
		TDG/ch01s02.html TDG/ch04s02.html \
		TDG/ch08s02.html TDG/index.html \
		TDG/re02.html TDG/ch01s03.html \
		TDG/ch05.html TDG/ch09.html \
		TDG/pngbehavior.htc TDG/re03.html \
		TDG/ch02.html TDG/ch06.html \
		TDG/ch09s02.html TDG/pr01.html \
		TDG/re04.html TDG/ch03.html \
		TDG/ch06s02.html TDG/ch09s03.html \
		TDG/pr01s02.html TDG/re05.html \
		TDG/ch03s02.html TDG/ch06s03.html \
		TDG/ch09s04.html TDG/pt01.html \
		TDG/re06.html TDG/ch03s03.html \
		TDG/ch06s04.html TDG/ch09s05.html \
		TDG/pt02.html TDG/re07.html \
		TDG/img/custom2.png TDG/img/custom5.png \
		TDG/img/example.png TDG/img/pearsmall.gif \
		TDG/img/basic1.png TDG/img/custom3.png \
		TDG/img/custom6.png TDG/img/multiple1.png \
		TDG/img/template1.png TDG/img/custom1.png \
		TDG/img/custom4.png TDG/img/custom7.png \
		TDG/img/multiple2.png \
		TDG/img/admons/caution.png \
		TDG/img/admons/important.png \
		TDG/img/admons/note.png \
		TDG/img/admons/tip.png \
		TDG/img/admons/warning.png

EXAMPLES=	bluestar-12.gif down.png \
		goldstar-12.gif itdynamic.html \
		qfams_basic_1.php qfams_basic_2.php \
		qfams_custom_1.php qfams_custom_2.php \
		qfams_custom_3.php qfams_custom_4.php \
		qfams_custom_5.php qfams_custom_6.php \
		qfams_custom_7.php \
		qfams_multiple_1.php qfams_multiple_2.php \
		qfams_template_1.php up.png

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
