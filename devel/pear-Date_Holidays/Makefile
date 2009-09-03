# New ports collection makefile for:	pear-Date_Holidays
# Date created:		2006-06-16
# Whom:			Thomas Abthorpe <thomas@goodking.ca>
#
# $FreeBSD$
#

PORTNAME=	Date_Holidays
PORTVERSION=	0.21.4
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR driver based class to calculate holidays

BUILD_DEPENDS=	${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Date
FILES=		Holidays.php \
		Holidays/Driver/Christian.php \
		Holidays/Driver/Composite.php \
		Holidays/Driver/EasternChristian.php \
		Holidays/Driver/Jewish.php \
		Holidays/Filter/Blacklist.php \
		Holidays/Filter/Composite.php \
		Holidays/Filter/Whitelist.php \
		Holidays/Driver.php \
		Holidays/Filter.php \
		Holidays/Holiday.php \
		lang/Christian/de_DE.ser \
		lang/Christian/de_DE.xml \
		lang/Christian/en_EN.ser \
		lang/Christian/en_EN.xml \
		lang/Christian/fr_FR.ser \
		lang/Christian/fr_FR.xml \
		lang/Christian/it_IT.ser \
		lang/Christian/it_IT.xml

EXAMPLES=	addingTranslations.php creating_drivers.php \
		fetchingInstalledDrivers.php languagefile-with-properties.xml \
		usingCompositeDriver.php usingStandaloneDriver.php

TESTS=		AllTests.php AllTestsUndeployed.php \
		Date_Holidays_Bugfix_Retests_TestSuite.php \
		Date_Holidays_Driver_Christian_TestSuite.php \
		Date_Holidays_Driver_Jewish_TestSuite.php \
		Date_Holidays_Driver_TestSuite.php \
		Date_Holidays_Driver_TestSuite.xml \
		Date_Holidays_TestSuite.php \
		Example.php testHolidays2005stampsAndSavingsDay.php \
		test_getHolidays.php test_missingLocale.php

LATEST_LINK=	pear-Date_Holidays
OPTIONS=	PEAR_CONSOLE_GETARGS "devel/pear-Console_Getargs" off

.include <bsd.port.pre.mk>

.if defined(PEAR_CONSOLE_GETARGS) || defined(WITH_PEAR_CONSOLE_GETARGS)
BUILD_DEPENDS+=${PEARDIR}/Console/Getargs.php:${PORTSDIR}/devel/pear-Console_Getargs
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
