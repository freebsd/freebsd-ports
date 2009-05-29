# New ports collection makefile for:   pear-DB_DataObject_FormBuilder
# Date created:        24 August 2004
# Whom:                Antonio Carlos Venancio Junior (<antonio@php.net>)
#
# $FreeBSD$
#

PORTNAME=	DB_DataObject_FormBuilder
PORTVERSION=	1.0.0
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Automatically build HTML_QuickForm objects using DB_DataObject

BUILD_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm \
		${PEARDIR}/DB/DataObject.php:${PORTSDIR}/databases/pear-DB_DataObject
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-DB_DataObject_FormBuilder
OPTIONS=	PEAR_DATE "PEAR::Date support" off \
		PEAR_HTML_TABLE "PEAR::HTML_Table support" off

CATEGORY=	DB/DataObject
FILES=		FormBuilder.php FormBuilder/QuickForm.php \
		FormBuilder/QuickForm/SubForm.php \
		FormBuilder/QuickForm/SubFormFB.php \
		tools/fix0.9.0Files.php tools/fixPre1.52CVSFiles.php

TESTS=		array2date.phpt config.php \
		configAndOverride.phpt create.phpt \
		createSubmit.phpt createWithDriver.phpt \
		createWithOptions.phpt dateElement.phpt \
		dateOptionsCallbacks.phpt elementNamePrefix_Postfix.phpt \
		enum.phpt existingRecordUpdated.phpt \
		forceInsert.phpt formHeaderText.phpt \
		getForm.phpt links.phpt \
		movie.sql newRecordInserted.phpt \
		notNullFieldRequired.phpt primaryKeyIsHidden.phpt \
		submitText.phpt textElement.phpt \
		typeArrays.phpt

EXAMPLES=	classes/Category.php classes/Manufacturer.php \
		classes/Product.php classes/formbuilder.ini \
		classes/formbuilder.links.ini config_inc.php \
		dataObject.ini index.php \
		sql/schema.gif sql/schema.sql

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_DATE)
RUN_DEPENDS+=	${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date
.endif

.if defined(WITH_PEAR_HTML_TABLE)
RUN_DEPENDS+=	${PEARDIR}/HTML/Table.php:${PORTSDIR}/devel/pear-HTML_Table
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
