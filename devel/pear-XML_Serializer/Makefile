# Ports collection makefile for:  pear-XML_Serializer
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_Serializer
PORTVERSION=	0.6
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Swiss-army knive for reading and writing XML files

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

MANIFEST=	Serializer.php Unserializer.php

do-install:
	@${MKDIR} ${PEARDIR}/XML
.for FILE in ${MANIFEST}
	@${CP} -p ${WRKSRC}/${FILE} ${PEARDIR}/XML
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/XML/${FILE}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -Rp ${WRKSRC}/examples/* ${DOCSDIR}
	@${ECHO_MSG} "===> Examples installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
