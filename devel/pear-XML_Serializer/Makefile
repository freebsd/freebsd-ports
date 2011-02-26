# Ports collection makefile for:  pear-XML_Serializer
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_Serializer
PORTVERSION=	0.20.2
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Swiss-army knive for reading and writing XML files

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
RUN_DEPENDS=	${BUILD_DEPENDS}

PEAR_CATSRC=	yes

CATEGORY=	XML
FILES=		Serializer.php Unserializer.php
EXAMPLES=	example.xml serializeAndEncode.php \
		serializeAndReturn.php serializeCData.php \
		serializeIndexedArray.php \
		serializeIndexedArrayWithContext.php \
		serializeNullProperties.php serializeObject.php \
		serializeRDF.php Serializer_Bug7112.php \
		serializeSelectiveAttributes.php \
		serializeWithAttributes.php \
		serializeWithAttributes2.php \
		serializeWithComment.php serializeWithDtd.php \
		serializeWithIndentedAttributes.php \
		serializeWithNamespace.php serializeWithTagMap.php \
		unserializeAnyXML.php unserializeClassNames.php \
		unserializeEncoded.php unserializeEnum.php \
		unserializeObject.php unserializeRDF.php \
		unserializeWhitespace.php \
		unserializeWithAttributes.php \
		unserializeWithTagMap.php \
		unserializeWithTypeGuessing.php
TESTS=		req-13564.phpt bug-13896.phpt bug-15602.phpt \
		Serializer_Arrays_TestCase.php \
		Serializer_Objects_TestCase.php \
		Serializer_Option_AttributesContent_TestCase.php \
		Serializer_Option_CDataSections_TestCase.php \
		Serializer_Option_ClassName_TestCase.php \
		Serializer_Option_Comment_TestCase.php \
		Serializer_Option_DocType_TestCase.php \
		Serializer_Option_DefaultTag_TestCase.php \
		Serializer_Option_EncodeFunc_TestCase.php \
		Serializer_Option_IgnoreNull_TestCase.php \
		Serializer_Option_Indent_TestCase.php \
		Serializer_Option_Linebreaks_TestCase.php \
		Serializer_Option_Mode_TestCase.php \
		Serializer_Option_Namespace_TestCase.php \
		Serializer_Option_ReturnResult_TestCase.php \
		Serializer_Option_RootAttributes_TestCase.php \
		Serializer_Option_RootName_TestCase.php \
		Serializer_Option_TagMap_TestCase.php \
		Serializer_Option_TypeHints_TestCase.php \
		Serializer_Option_XmlDeclaration_TestCase.php \
		Serializer_Scalars_TestCase.php \
		show_ScalarAsAttributes_usage.phpt \
		Unserializer_Arrays_TestCase.php \
		Unserializer_Objects_TestCase.php \
		Unserializer_Option_Encodings_TestCase.php \
		Unserializer_Option_GuessTypes_TestCase.php \
		Unserializer_Option_Whitespace_TestCase.php \
		Unserializer_Scalars_TestCase.php
DOCS=		todo.txt
_DOCSDIR=	doc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
