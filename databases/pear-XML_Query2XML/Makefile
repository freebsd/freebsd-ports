# Ports collection makefile for:  pear-XML_Query2xml
# Date created:			  23 March 2008
# Whom:				  wenheping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	XML_Query2XML
PORTVERSION=	1.7.1
CATEGORIES=	databases pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class transform SQL queries into XML data

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-XML_Query2xml
OPTIONS=	PEAR_MDB2 "Add support for pear-MDB2" Off \
		PEAR_Net_LDAP2 "Add support for pear-Net_LDAP2" Off

FILES=	XML/Query2XML.php XML/Query2XML/ISO9075Mapper.php \
	XML/Query2XML/Callback.php \
	XML/Query2XML/Data.php \
	XML/Query2XML/Data/Condition/NonEmpty.php \
	XML/Query2XML/Data/Condition.php \
	XML/Query2XML/Data/Processor/Base64.php \
	XML/Query2XML/Data/Processor/CDATA.php \
	XML/Query2XML/Data/Processor/Unserialize.php \
	XML/Query2XML/Data/Processor.php \
	XML/Query2XML/Data/Source/ColumnValue.php \
	XML/Query2XML/Data/Source/PHPCallback.php \
	XML/Query2XML/Data/Source/Static.php \
	XML/Query2XML/Data/Source.php \
	XML/Query2XML/Driver/ADOdb.php \
	XML/Query2XML/Driver/DB.php \
	XML/Query2XML/Driver/Caching.php \
	XML/Query2XML/Driver/LDAP.php \
	XML/Query2XML/Driver/MDB2.php \
	XML/Query2XML/Driver/PDO.php \
	XML/Query2XML/Driver/LDAP2.php

DOCS=	case01/case01.php case01/case01.xml case02/case02.log \
	case02/case02.php case02/case02.profile \
	case02/case02.xml case02/case02_debug.php \
	case03/case03.log case03/case03.php case03/case03.profile \
	case03/case03.xml case03/case03_debug.php \
	case04/case04.log case04/case04.php case04/case04.profile \
	case04/case04.xml case04/case04_debug.php case05/case05.log \
	case05/case05.php case05/case05.profile case05/case05.xml \
	case05/case05_debug.php case06/case06.log case06/case06.php \
	case06/case06.profile case06/case06.xml case06/case06_debug.php \
	case07/case07.log case07/case07.php case07/case07.profile \
	case07/case07.xml case07/case07_debug.php case08/case08.log \
	case08/case08.php case08/case08.profile case08/case08.xml \
	case08/case08_debug.php
_DOCSDIR=	cases

TESTS=	Query2XML_Tests.psql \
	Query2XML_Tests.sq2 \
	Query2XML_Tests.sql \
	XML_Query2XML/AllDBLayers/ADOdbDefault_db_init.php \
	XML_Query2XML/AllDBLayers/ADOdbDefault_skipif.php \
	XML_Query2XML/AllDBLayers/ADOdbException_db_init.php \
	XML_Query2XML/AllDBLayers/ADOdbException_skipif.php \
	XML_Query2XML/AllDBLayers/ADOdbPEAR_db_init.php \
	XML_Query2XML/AllDBLayers/ADOdbPEAR_skipif.php \
	XML_Query2XML/AllDBLayers/DB_db_init.php \
	XML_Query2XML/AllDBLayers/DB_skipif.php \
	XML_Query2XML/AllDBLayers/MDB2_db_init.php \
	XML_Query2XML/AllDBLayers/MDB2_skipif.php \
	XML_Query2XML/AllDBLayers/PDO_db_init.php \
	XML_Query2XML/AllDBLayers/PDO_skipif.php \
	XML_Query2XML/AllDBLayers/_addDOMChildren/throwXMLException_arrayWithBool.phpt \
	XML_Query2XML/AllDBLayers/_addDOMChildren/throwXMLException_arrayWithDouble.phpt \
	XML_Query2XML/AllDBLayers/_addDOMChildren/throwXMLException_arrayWithInt.phpt \
	XML_Query2XML/AllDBLayers/_addDOMChildren/throwXMLException_arrayWithObject.phpt \
	XML_Query2XML/AllDBLayers/_addDOMChildren/throwXMLException_arrayWithString.phpt \
	XML_Query2XML/AllDBLayers/_appendTextChildNode/throwXMLException.phpt \
	XML_Query2XML/AllDBLayers/_applyColumnStringToRecord/callbacks.phpt \
	XML_Query2XML/AllDBLayers/_applyColumnStringToRecord/throwConfigException_callback_function1.phpt \
	XML_Query2XML/AllDBLayers/_applyColumnStringToRecord/throwConfigException_callback_function2.phpt \
	XML_Query2XML/AllDBLayers/_applyColumnStringToRecord/throwConfigException_callback_method1.phpt \
	XML_Query2XML/AllDBLayers/_applyColumnStringToRecord/throwConfigException_callback_method2.phpt \
	XML_Query2XML/AllDBLayers/_applyColumnStringToRecord/throwConfigException_element1.phpt \
	XML_Query2XML/AllDBLayers/_applyColumnStringToRecord/throwConfigException_element2.phpt \
	XML_Query2XML/AllDBLayers/_applyColumnStringToRecord/throwConfigException_idcolumn.phpt \
	XML_Query2XML/AllDBLayers/_applyColumnStringToRecord/throwXMLException_unserialize.phpt \
	XML_Query2XML/AllDBLayers/_applySqlOptionsToRecord/throwConfigException_mergeMasterFalse.phpt \
	XML_Query2XML/AllDBLayers/_applySqlOptionsToRecord/throwConfigException_mergeMasterTrue.phpt \
	XML_Query2XML/AllDBLayers/_createDOMElement/throwXMLException_elementInvalid1.phpt \
	XML_Query2XML/AllDBLayers/_createDOMElement/throwXMLException_elementInvalid2.phpt \
	XML_Query2XML/AllDBLayers/_createDOMElement/throwXMLException_roottagOptionInvalid1.phpt \
	XML_Query2XML/AllDBLayers/_createDOMElement/throwXMLException_roottagOptionInvalid2.phpt \
	XML_Query2XML/AllDBLayers/_createDOMElement/throwXMLException_rowtagOptionInvalid.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/basics.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/encoder_default.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/encoder_false.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/encoder_function.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/encoder_nonStaticMethod.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/encoder_null.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/encoder_overwritten_default_false.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/encoder_overwritten_default_false2.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/encoder_overwritten_default_false_function.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/encoder_overwritten_null_false_nonStaticMethodString.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/encoder_overwritten_null_false_staticMethodString.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/encoder_staticMethodArray.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/encoder_staticMethodString.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/throwXMLException.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/within_complexAttributeSpecificationValue.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/within_complexElementSpecificationValue.phpt \
	XML_Query2XML/AllDBLayers/_executeEncoder/within_simpleAttributeSpecification.phpt \
	XML_Query2XML/AllDBLayers/_getNestedXMLRecord/throwConfigException_attributeSpecWrongType.phpt \
	XML_Query2XML/AllDBLayers/_getNestedXMLRecord/throwConfigException_idcolumnOptionWrongTypeArray.phpt \
	XML_Query2XML/AllDBLayers/_getNestedXMLRecord/throwConfigException_idcolumnOptionWrongTypeObject.phpt \
	XML_Query2XML/AllDBLayers/_mapSQLIdentifierToXMLName/throwXMLException.phpt \
	XML_Query2XML/AllDBLayers/_prepareAndExecute/throwDBException_complexQuery.phpt \
	XML_Query2XML/AllDBLayers/_prepareAndExecute/throwDBException_simpleQuery.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_attributesOptionWrongType.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_callbackInterface_complexAttributeSpec.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_callbackInterface_complexElementSpec.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_callbackInterface_condition.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_callbackInterface_data.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_callbackInterface_idColumn.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_callbackInterface_noArrayKey.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_callbackInterface_simpleAttributeSpec.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_callbackInterface_simpleElementSpec.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_dataOptionWrongType.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_driverOptionWrongType.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_elementsOptionWrongType.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_encoderNotCallableFunction.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_encoderNotCallableNonstaticMethod.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_encoderNotCallableStaticMethod1.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_encoderNotCallableStaticMethod2.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_idcolumnOptionMissing.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_mapperNotCallableFunction.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_mapperNotCallableNonstaticMethod.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_mapperNotCallableStaticMethod1.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_mapperNotCallableStaticMethod2.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_mergeselectiveOptionWrongType.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_prefix_noArrayKey.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_queryOptionMissing.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_sqlOptionWrongType.phpt \
	XML_Query2XML/AllDBLayers/_preprocessOptions/throwConfigException_valueOptionMissing.phpt \
	XML_Query2XML/AllDBLayers/_processComplexElementSpecification/condition_function.phpt \
	XML_Query2XML/AllDBLayers/_processComplexElementSpecification/condition_staticMethod.phpt \
	XML_Query2XML/AllDBLayers/_processComplexElementSpecification/rethrowConfigException.phpt \
	XML_Query2XML/AllDBLayers/_setDOMAttribute/throwXMLException.phpt \
	XML_Query2XML/AllDBLayers/clearProfile/clearProfile.phpt \
	XML_Query2XML/AllDBLayers/db_init.php \
	XML_Query2XML/AllDBLayers/disableDebugLog/disableDebugLog.phpt \
	XML_Query2XML/AllDBLayers/enableDebugLog/enableDebugLog.phpt \
	XML_Query2XML/AllDBLayers/enableDebugLog/enableDebugLog_cached.phpt \
	XML_Query2XML/AllDBLayers/enableDebugLog/enableDebugLog_twoVars.phpt \
	XML_Query2XML/AllDBLayers/enableDebugLog/enableDebugLog_uncached.phpt \
	XML_Query2XML/AllDBLayers/getFlatXML/case01.phpt \
	XML_Query2XML/AllDBLayers/getFlatXML/simpleSelect.phpt \
	XML_Query2XML/AllDBLayers/getFlatXML/throwDBException.phpt \
	XML_Query2XML/AllDBLayers/getGlobalOption/configException_noSuchOption.phpt \
	XML_Query2XML/AllDBLayers/getGlobalOption/hidden_container_prefix.phpt \
	XML_Query2XML/AllDBLayers/getProfile/getProfile.phpt \
	XML_Query2XML/AllDBLayers/getRawProfile/getRawProfile.phpt \
	XML_Query2XML/AllDBLayers/getXML/asteriskShortcut_attributes1.phpt \
	XML_Query2XML/AllDBLayers/getXML/asteriskShortcut_attributes2.phpt \
	XML_Query2XML/AllDBLayers/getXML/asteriskShortcut_attributes3.phpt \
	XML_Query2XML/AllDBLayers/getXML/asteriskShortcut_attributes4.phpt \
	XML_Query2XML/AllDBLayers/getXML/asteriskShortcut_attributes5.phpt \
	XML_Query2XML/AllDBLayers/getXML/asteriskShortcut_attributes6.phpt \
	XML_Query2XML/AllDBLayers/getXML/asteriskShortcut_elements1.phpt \
	XML_Query2XML/AllDBLayers/getXML/asteriskShortcut_elements2.phpt \
	XML_Query2XML/AllDBLayers/getXML/asteriskShortcut_elements3.phpt \
	XML_Query2XML/AllDBLayers/getXML/asteriskShortcut_elements4.phpt \
	XML_Query2XML/AllDBLayers/getXML/asteriskShortcut_elements5.phpt \
	XML_Query2XML/AllDBLayers/getXML/asteriskShortcut_elements6.phpt \
	XML_Query2XML/AllDBLayers/getXML/base64Prefix_callback.phpt \
	XML_Query2XML/AllDBLayers/getXML/base64Prefix_callback_conditionalPrefix.phpt \
	XML_Query2XML/AllDBLayers/getXML/base64Prefix_columnName.phpt \
	XML_Query2XML/AllDBLayers/getXML/base64Prefix_columnName_conditionalPrefix.phpt \
	XML_Query2XML/AllDBLayers/getXML/base64Prefix_staticString.phpt \
	XML_Query2XML/AllDBLayers/getXML/base64Prefix_staticString_conditionalPrefix.phpt \
	XML_Query2XML/AllDBLayers/getXML/caching_cached.phpt \
	XML_Query2XML/AllDBLayers/getXML/caching_cached_different_drivers.phpt \
	XML_Query2XML/AllDBLayers/getXML/caching_cached_limit.phpt \
	XML_Query2XML/AllDBLayers/getXML/caching_cached_limits.phpt \
	XML_Query2XML/AllDBLayers/getXML/caching_cached_multiple_queries.phpt \
	XML_Query2XML/AllDBLayers/getXML/caching_cached_offset.phpt \
	XML_Query2XML/AllDBLayers/getXML/caching_uncached.phpt \
	XML_Query2XML/AllDBLayers/getXML/callbackInterface_complexAttributeSpec.phpt \
	XML_Query2XML/AllDBLayers/getXML/callbackInterface_complexElementSpec.phpt \
	XML_Query2XML/AllDBLayers/getXML/callbackInterface_condition.phpt \
	XML_Query2XML/AllDBLayers/getXML/callbackInterface_data.phpt \
	XML_Query2XML/AllDBLayers/getXML/callbackInterface_idColumn.phpt \
	XML_Query2XML/AllDBLayers/getXML/callbackInterface_simpleAttributeSpec.phpt \
	XML_Query2XML/AllDBLayers/getXML/callbackInterface_simpleElementSpec.phpt \
	XML_Query2XML/AllDBLayers/getXML/callbackReturnDOMNode.phpt \
	XML_Query2XML/AllDBLayers/getXML/callbackReturnDOMNodeArray.phpt \
	XML_Query2XML/AllDBLayers/getXML/callbackReturnDOMNodeArray_parentHidden.phpt \
	XML_Query2XML/AllDBLayers/getXML/callbackReturnDOMNode_parentHidden.phpt \
	XML_Query2XML/AllDBLayers/getXML/case02.phpt \
	XML_Query2XML/AllDBLayers/getXML/case03.phpt \
	XML_Query2XML/AllDBLayers/getXML/case04.phpt \
	XML_Query2XML/AllDBLayers/getXML/case05.phpt \
	XML_Query2XML/AllDBLayers/getXML/case06.phpt \
	XML_Query2XML/AllDBLayers/getXML/case07.phpt \
	XML_Query2XML/AllDBLayers/getXML/case08.phpt \
	XML_Query2XML/AllDBLayers/getXML/cdataPrefix_base64Prefix.phpt \
	XML_Query2XML/AllDBLayers/getXML/cdataPrefix_callback.phpt \
	XML_Query2XML/AllDBLayers/getXML/cdataPrefix_callback_conditionalPrefix.phpt \
	XML_Query2XML/AllDBLayers/getXML/cdataPrefix_columnName.phpt \
	XML_Query2XML/AllDBLayers/getXML/cdataPrefix_columnName_conditionalPrefix.phpt \
	XML_Query2XML/AllDBLayers/getXML/cdataPrefix_emptyCdata.phpt \
	XML_Query2XML/AllDBLayers/getXML/cdataPrefix_staticString.phpt \
	XML_Query2XML/AllDBLayers/getXML/cdataPrefix_staticString_conditionalPrefix.phpt \
	XML_Query2XML/AllDBLayers/getXML/cdataPrefix_throwException2_invalidForAttribute.phpt \
	XML_Query2XML/AllDBLayers/getXML/cdataPrefix_throwException_invalidForAttribute.phpt \
	XML_Query2XML/AllDBLayers/getXML/complexAttributeSpecification_complexQuerySpecification.phpt \
	XML_Query2XML/AllDBLayers/getXML/complexAttributeSpecification_complexQuerySpecification_valueCallback.phpt \
	XML_Query2XML/AllDBLayers/getXML/complexAttributeSpecification_conditionOption.phpt \
	XML_Query2XML/AllDBLayers/getXML/complexAttributeSpecification_simpleQuerySpecification.phpt \
	XML_Query2XML/AllDBLayers/getXML/complexAttributeSpecification_valuePrefixes.phpt \
	XML_Query2XML/AllDBLayers/getXML/complexElementSpecification_conditionOption1.phpt \
	XML_Query2XML/AllDBLayers/getXML/complexElementSpecification_conditionOption2.phpt \
	XML_Query2XML/AllDBLayers/getXML/conditionPrefix_attribute_callback.phpt \
	XML_Query2XML/AllDBLayers/getXML/conditionPrefix_attribute_columnName.phpt \
	XML_Query2XML/AllDBLayers/getXML/conditionPrefix_attribute_staticText.phpt \
	XML_Query2XML/AllDBLayers/getXML/conditionPrefix_element_callback.phpt \
	XML_Query2XML/AllDBLayers/getXML/conditionPrefix_element_columnName.phpt \
	XML_Query2XML/AllDBLayers/getXML/conditionPrefix_element_staticText.phpt \
	XML_Query2XML/AllDBLayers/getXML/conditionPrefix_value_callback.phpt \
	XML_Query2XML/AllDBLayers/getXML/conditionPrefix_value_columnName.phpt \
	XML_Query2XML/AllDBLayers/getXML/conditionPrefix_value_staticText.phpt \
	XML_Query2XML/AllDBLayers/getXML/dynamicRowTag_callback.phpt \
	XML_Query2XML/AllDBLayers/getXML/dynamicRowTag_columnName.phpt \
	XML_Query2XML/AllDBLayers/getXML/dynamicRowTag_columnName_ignoreRowTag.phpt \
	XML_Query2XML/AllDBLayers/getXML/dynamicRowTag_columnName_onRootLevel.phpt \
	XML_Query2XML/AllDBLayers/getXML/dynamicRowTag_commandObject.phpt \
	XML_Query2XML/AllDBLayers/getXML/dynamicRowTag_staticString.phpt \
	XML_Query2XML/AllDBLayers/getXML/idcolumn_false1.phpt \
	XML_Query2XML/AllDBLayers/getXML/idcolumn_false2.phpt \
	XML_Query2XML/AllDBLayers/getXML/offsetlimit.phpt \
	XML_Query2XML/AllDBLayers/getXML/offsetlimit_driver.phpt \
	XML_Query2XML/AllDBLayers/getXML/offsetlimit_limit_zero.phpt \
	XML_Query2XML/AllDBLayers/getXML/offsetlimit_throwConfigException_limit_not_numeric.phpt \
	XML_Query2XML/AllDBLayers/getXML/offsetlimit_throwConfigException_offset_not_numeric.phpt \
	XML_Query2XML/AllDBLayers/getXML/sql_argument_false1.phpt \
	XML_Query2XML/AllDBLayers/getXML/sql_argument_false2.phpt \
	XML_Query2XML/AllDBLayers/getXML/sql_options_single_record.phpt \
	XML_Query2XML/AllDBLayers/getXML/sql_options_single_record_emptyResultSet.phpt \
	XML_Query2XML/AllDBLayers/getXML/sql_options_single_record_emptyResultSet_uncached.phpt \
	XML_Query2XML/AllDBLayers/getXML/sql_options_single_record_uncached.phpt \
	XML_Query2XML/AllDBLayers/getXML/throwDBException.phpt \
	XML_Query2XML/AllDBLayers/getXML/throwDBException_nullResultSet_complexQuery_multipleRecords.phpt \
	XML_Query2XML/AllDBLayers/getXML/throwDBException_nullResultSet_complexQuery_singleRecord.phpt \
	XML_Query2XML/AllDBLayers/getXML/throwDBException_nullResultSet_simpleQuery_multipleRecords.phpt \
	XML_Query2XML/AllDBLayers/getXML/throwDBException_nullResultSet_simpleQuery_singleRecord.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_complexElement_callback.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_complexElement_callbackEmpty.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_complexElement_columnName.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_complexElement_columnNameEmpty.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_complexElement_staticString.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_complexElement_staticStringEmpty.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_scenariosContainerAlwaysPresent.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_scenariosContainerOnlyPresentIfChildren.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_scenariosNoContainer.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_simpleElement_callback.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_simpleElement_callbackEmpty.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_simpleElement_columnName.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_simpleElement_columnNameEmpty.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_simpleElement_staticString.phpt \
	XML_Query2XML/AllDBLayers/getXML/unserializationPrefix_simpleElement_staticStringEmpty.phpt \
	XML_Query2XML/AllDBLayers/setGlobalOption/configException_hidden_container_prefix_wrongTypeEmptyStr.phpt \
	XML_Query2XML/AllDBLayers/setGlobalOption/configException_hidden_container_prefix_wrongTypeObject.phpt \
	XML_Query2XML/AllDBLayers/setGlobalOption/configException_noSuchOption.phpt \
	XML_Query2XML/AllDBLayers/setGlobalOption/hidden_container_prefix.phpt \
	XML_Query2XML/AllDBLayers/skipif.php \
	XML_Query2XML/AllDBLayers/startProfiling/startProfiling.phpt \
	XML_Query2XML/AllDBLayers/stopProfiling/stopProfiling.phpt \
	XML_Query2XML/LDAP/XML_Query2XML_Driver_LDAP-preprocessQuery/regularOperation.phpt \
	XML_Query2XML/LDAP/XML_Query2XML_Driver_LDAP-preprocessQuery/throwConfigException_queryNotAnArray.phpt \
	XML_Query2XML/LDAP/getXML/complexElementSpecification_multiValueLDAPAttributes.phpt \
	XML_Query2XML/LDAP/getXML/placeholders.phpt \
	XML_Query2XML/LDAP/getXML/placeholders_alternative.phpt \
	XML_Query2XML/LDAP/getXML/placeholders_alternative_multichar.phpt \
	XML_Query2XML/LDAP/getXML/simpleElementSpecification.phpt \
	XML_Query2XML/LDAP/getXML/simpleElementSpecification_optionalLDAPAttributes.phpt \
	XML_Query2XML/LDAP/getXML/throwLDAPException_queryError.phpt \
	XML_Query2XML/LDAP/ldap_init.php \
	XML_Query2XML/LDAP/skipif.php \
	XML_Query2XML/settings.php \
	XML_Query2XML_ISO9075Mapper/map/_X_UC.phpt \
	XML_Query2XML_ISO9075Mapper/map/_x.phpt \
	XML_Query2XML_ISO9075Mapper/map/at.phpt \
	XML_Query2XML_ISO9075Mapper/map/colon.phpt \
	XML_Query2XML_ISO9075Mapper/map/curlyBraceClose.phpt \
	XML_Query2XML_ISO9075Mapper/map/curlyBraceOpen.phpt \
	XML_Query2XML_ISO9075Mapper/map/equalSign.phpt \
	XML_Query2XML_ISO9075Mapper/map/greaterThan.phpt \
	XML_Query2XML_ISO9075Mapper/map/invalidNameStartChars.phpt \
	XML_Query2XML_ISO9075Mapper/map/invalidNametChars.phpt \
	XML_Query2XML_ISO9075Mapper/map/lessThan.phpt \
	XML_Query2XML_ISO9075Mapper/map/poundSign.phpt \
	XML_Query2XML_ISO9075Mapper/map/semicolon.phpt \
	XML_Query2XML_ISO9075Mapper/map/space.phpt \
	XML_Query2XML_ISO9075Mapper/map/startWith_XML_UC.phpt \
	XML_Query2XML_ISO9075Mapper/map/startWith_xml.phpt \
	XML_Query2XML_ISO9075Mapper/map/throwException1.phpt \
	XML_Query2XML_ISO9075Mapper/map/throwException2.phpt \
	XML_Query2XML_ISO9075Mapper/map/throwException3.phpt \
	XML_Query2XML_ISO9075Mapper/map/unmodified1.phpt \
	XML_Query2XML_ISO9075Mapper/map/unmodified2.phpt \
	XML_Query2XML_ISO9075Mapper/map/validNameChars.phpt \
	XML_Query2XML_ISO9075Mapper/map/validNameStartChars.phpt \
	XML_Query2XML_ISO9075Mapper/map/validSpecialChars1.phpt \
	XML_Query2XML_ISO9075Mapper/map/validSpecialChars2.phpt \
	XML_Query2XML_ISO9075Mapper/map/variousChars.phpt \
	XML_Query2XML_ISO9075Mapper/skipif.php
_TESTSDIR=	tests

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_MDB2)
BUILD_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PEAR_Net_LDAP2)
BUILD_DEPENDS+=	${PEARDIR}/Net/LDAP2.php:${PORTSDIR}/net/pear-Net_LDAP2
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
