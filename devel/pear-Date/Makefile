# Ports collection makefile for:  pear-Date
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Date
PORTVERSION=	1.4.7
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Date and Time Zone Classes

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Date.php Date/Calc.php Date/Human.php Date/TimeZone.php \
		Date/Span.php
TESTS=		calc.php testunit.php testunit_date.php testunit_date_span.php \
		test_calc.php test_date_methods_span.php \
		bugs/bug-674.phpt bugs/bug-727-1.phpt bugs/bug-727-2.phpt \
		bugs/bug-727-3.phpt bugs/bug-727-4.phpt bugs/bug-967.phpt \
		bugs/bug-8912.phpt bugs/bug-9213.phpt bugs/bug-9414.phpt
DOCS=		TODO LICENSE

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
