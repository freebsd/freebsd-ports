# Ports collection makefile for:  pear-Date
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Date
PORTVERSION=	1.4.3
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR Date and Time Zone Classes

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Date.php Date/Calc.php Date/Human.php Date/Span.php	\
		Date/TimeZone.php
TESTS=		test_calc.php test_date_methods_span.php testunit.php	\
		testunit_date.php testunit_date_span.php wknotest.txt	\
		bug674.php bug727_1.php bug727_2.php bug727_3.php	\
		bug727_4.php bug967.php weeksinmonth_4_monday.txt	\
		weeksinmonth_4_sunday.txt weeksinmonth_rdm_monday.txt	\
		weeksinmonth_rdm_sunday.txt
DOCS=		TODO
_DOCSDIR=	.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
