# Ports collection makefile for:  pear-XML_Tree
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_Tree
PORTVERSION=	1.1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class for representing XML data in a tree structure

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

do-install:
	@${MKDIR} ${PEARDIR}/XML/Tree
	@${CP} -p ${WRKSRC}/Tree.php ${PEARDIR}/XML
	@${CP} -p ${WRKSRC}/Tree/Node.php ${PEARDIR}/XML/Tree
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/XML/Tree.php
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/XML/Tree

.include <bsd.port.post.mk>
