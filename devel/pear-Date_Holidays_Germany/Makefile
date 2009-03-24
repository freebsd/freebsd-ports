# New ports collection makefile for:	pear-Date_Holidays_Germany
# Date created:		2008-06-04
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Date_Holidays_Germany
PORTVERSION=	0.1.2
CATEGORIES=	devel www pear

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Driver based class to calculate holidays in Germany

BUILD_DEPENDS=	${PEARDIR}/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Date
FILES=		Holidays/Driver/Germany.php \
		Holidays/Filter/Germany/BadenWuerttemberg.php \
		Holidays/Filter/Germany/Bavaria.php \
		Holidays/Filter/Germany/Berlin.php \
		Holidays/Filter/Germany/Brandenburg.php \
		Holidays/Filter/Germany/Bremen.php \
		Holidays/Filter/Germany/Hamburg.php \
		Holidays/Filter/Germany/Hesse.php \
		Holidays/Filter/Germany/LowerSaxony.php \
		Holidays/Filter/Germany/MecklenburgWesternPomerania.php \
		Holidays/Filter/Germany/NorthRhineWestphalia.php \
		Holidays/Filter/Germany/Official.php \
		Holidays/Filter/Germany/RhinelandPalatinate.php \
		Holidays/Filter/Germany/Saarland.php \
		Holidays/Filter/Germany/Saxony.php \
		Holidays/Filter/Germany/SaxonyAnhalt.php \
		Holidays/Filter/Germany/SchleswigHolstein.php \
		Holidays/Filter/Germany/Thuringia.php \
		lang/Germany/de_DE.ser \
		lang/Germany/de_DE.xml \
		lang/Germany/en_EN.ser \
		lang/Germany/en_EN.xml \
		lang/Germany/fr_FR.ser \
		lang/Germany/fr_FR.xml
TESTS=		Date_Holidays_Driver_Germany_TestSuite.php

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
