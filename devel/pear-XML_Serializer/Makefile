# Ports collection makefile for:  pear-XML_Serializer
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_Serializer
PORTVERSION=	0.19.2
CATEGORIES=	devel www pear

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	PEAR Swiss-army knive for reading and writing XML files

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	XML
FILES=		Serializer.php Unserializer.php
EXAMPLES=	Serializer_Bug7112.php serializeWithDtd.php \
		example.xml serializeWithIndentedAttributes.php \
		serializeAndEncode.php serializeWithNamespace.php \
		serializeAndReturn.php serializeWithTagMap.php \
		serializeCData.php unserializeAnyXML.php \
		serializeIndexedArray.php unserializeClassNames.php \
		serializeIndexedArrayWithContext.php unserializeEncoded.php \
		serializeNullProperties.php unserializeEnum.php \
		serializeObject.php unserializeObject.php \
		serializeRDF.php unserializeRDF.php \
		serializeSelectiveAttributes.php unserializeWhitespace.php \
		serializeWithAttributes.php unserializeWithAttributes.php \
		serializeWithAttributes2.php unserializeWithTagMap.php \
		serializeWithComment.php unserializeWithTypeGuessing.php
DOCS=		todo.txt
_DOCSDIR=	doc

post-extract:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" ${WRKSRC}/${file}
	@${FIND} ${WRKSRC} -name "*.bak" -delete
.endfor
.for file in ${EXAMPLES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" ${WRKSRC}/examples/${file}
	@${FIND} ${WRKSRC}/examples -name "*.bak" -delete
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
