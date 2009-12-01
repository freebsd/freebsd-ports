# Ports collection makefile for:  pear-XML_Util
# Date created:			  03 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_Util
PORTVERSION=	1.2.1
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR XML utility class

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	XML
FILES=		Util.php
EXAMPLES=	example.php example2.php
TESTS=		AllTests.php testBasic_apiVersion.phpt \
		testBasic_attributesToString.phpt \
		testBasic_collapseEmptyTags.phpt \
		testBasic_createCDataSection.phpt \
		testBasic_createComment.phpt \
		testBasic_createEndElement.phpt \
		testBasic_createStartElement.phpt \
		testBasic_createTag.phpt \
		testBasic_createTagFromArray.phpt \
		testBasic_getDocTypeDeclaration.phpt \
		testBasic_getXmlDeclaration.phpt \
		testBasic_isValidName.phpt \
		testBasic_raiseError.phpt \
		testBasic_replaceEntities.phpt \
		testBasic_reverseEntities.phpt \
		testBasic_splitQualifiedName.phpt \
		testBug_4950.phpt testBug_5392.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
