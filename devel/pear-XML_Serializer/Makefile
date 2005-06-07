# Ports collection makefile for:  pear-XML_Serializer
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_Serializer
PORTVERSION=	0.16.0
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR Swiss-army knive for reading and writing XML files

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes

CATEGORY=	XML
FILES=		Serializer.php Unserializer.php
EXAMPLES=	example.xml serializeAndEncode.php serializeAndReturn.php \
		serializeArrayWithObjects.php serializeEmptyArray.php \
		serializeIndexedArray.php serializeNullProperties.php \
		serializeObject.php serializeRDF.php serializeWithAttributes.php \
		serializeWithAttributes2.php serializeWithComment.php \
		serializeWithDtd.php serializeWithIndentedAttributes.php \
		serializeWithNamespace.php serializeWithTagMap.php \
		unserializeAnyXML.php unserializeClassNames.php \
		unserializeEncoded.php unserializeEnum.php unserializeObject.php \
		unserializeRDF.php unserializeWithAttributes.php \
		unserializeWithTagMap.php
DOCS=		todo.txt
_DOCSDIR=	doc

post-extract:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" ${WRKSRC}/${file}
.endfor
.for file in ${EXAMPLES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" ${WRKSRC}/examples/${file}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
