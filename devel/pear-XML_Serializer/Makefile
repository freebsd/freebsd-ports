# Ports collection makefile for:  pear-XML_Serializer
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_Serializer
PORTVERSION=	0.9.1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Swiss-army knive for reading and writing XML files

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util

CATEGORY=	XML
FILES=		Serializer.php Unserializer.php
EXAMPLES=	example.xml serializeIndexedArray.php serializeObject.php \
		serializeRDF.php serializeWithAttributes.php serializeWithDtd.php \
		serializeWithIndentedAttributes.php unserializeAnyXML.php \
		unserializeObject.php unserializeRDF.php unserializeWithAttributes.php
DOCS=		todo.txt
_DOCSDIR=	doc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
