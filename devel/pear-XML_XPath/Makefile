# Ports collection makefile for:  pear-XML_XPath
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_XPath
PORTVERSION=	1.2
CATEGORIES=	devel www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class provided an XPath/DOM XML manipulation

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

MANIFEST=	common.php error.php result.php

do-install:
	@${MKDIR} ${PEARDIR}/XPath
	@${CP} -p ${WRKSRC}/XPath.php ${PEARDIR}
.for FILE in ${MANIFEST}
	@${CP} -p ${WRKSRC}/XPath/${FILE} ${PEARDIR}/XPath
.endfor
		@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/XPath.php
		@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/XPath
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -p ${WRKSRC}/docs/XML_XPath_example.php ${DOCSDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
