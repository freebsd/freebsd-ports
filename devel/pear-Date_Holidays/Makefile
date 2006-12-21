# New ports collection makefile for:	pear-Date_Holidays
# Date created:		2006-06-16
# Whom:			Thomas Abthorpe <thomas@goodking.ca>
#
# $FreeBSD$
#

PORTNAME=	Date_Holidays
PORTVERSION=	0.17.0
CATEGORIES=	devel www pear
MASTER_SITES+=	http://www.goodking.ca/pub/files/PEAR/

MAINTAINER=	thomas@goodking.ca
COMMENT=	PEAR driver based class to calculate holidays

BUILD_DEPENDS=	${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Date
FILES=		Holidays.php \
		Holidays/Driver/Christian.php \
		Holidays/Driver/Composite.php \
		Holidays/Driver/Denmark.php \
		Holidays/Driver/Discordian.php \
		Holidays/Driver/Germany.php \
		Holidays/Driver/Jewish.php \
		Holidays/Driver/PHPdotNet.php \
		Holidays/Driver/Slovenia.php \
		Holidays/Driver/Sweden.php \
		Holidays/Driver/UNO.php \
		Holidays/Driver/USA.php \
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
		Holidays/Filter/Blacklist.php \
		Holidays/Filter/Composite.php \
		Holidays/Filter/Whitelist.php \
		Holidays/Driver.php \
		Holidays/Filter.php \
		Holidays/Holiday.php
EXAMPLES=	addingTranslations.php languagefile-with-properties.xml \
		creating_drivers.php usingCompositeDriver.php \
		fetchingInstalledDrivers.php usingStandaloneDriver.php
TESTS=		AllTests.php \
		AllTestsUndeployed.php \
		Date_Holidays_Driver_Christian_TestSuite.php \
		Date_Holidays_Driver_Germany_TestSuite.php \
		Date_Holidays_Driver_Jewish_TestSuite.php \
		Date_Holidays_Driver_PHPdotNet_TestSuite.php \
		Date_Holidays_Driver_Sweden_TestSuite.php \
		Date_Holidays_Driver_TestSuite.php \
		Date_Holidays_Driver_TestSuite.xml \
		Date_Holidays_Driver_UNO_TestSuite.php \
		Example.php \
		Date_Holidays_Driver_USA_TestSuite.php \
		Date_Holidays_TestSuite.php \
		testHolidays2005stampsAndSavingsDay.php \
		test_getHolidays.php \
		test_missingLocale.php

LATEST_LINK=	pear-Date_Holidays
OPTIONS=	PEAR_CONSOLE_GETARGS "devel/pear-Console_Getargs" off

.include <bsd.port.pre.mk>

.if defined(PEAR_CONSOLE_GETARGS) || defined(WITH_PEAR_CONSOLE_GETARGS)
BUILD_DEPENDS+=${PEARDIR}/Console/Getargs.php:${PORTSDIR}/devel/pear-Console_Getargs
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
