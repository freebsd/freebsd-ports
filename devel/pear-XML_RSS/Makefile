# Ports collection makefile for:  pear-XML_RSS
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_RSS
PORTVERSION=	0.9.2
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR RSS parser

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${PEARDIR}/XML/Tree.php:${PORTSDIR}/devel/pear-XML_Tree

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

TESTDIR=	${PEARDIR}/tests/${PORTNAME}

do-install:
	@${MKDIR} ${PEARDIR}/XML
	@${CP} -fp ${WRKSRC}/RSS.php ${PEARDIR}/XML
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/XML/RSS.php
	@${CHMOD} ${SHAREMODE} ${PEARDIR}/XML/RSS.php
.if !defined(NOPORTDOCS)
	@${MKDIR} ${TESTDIR}
	@${CP} -p ${WRKSRC}/tests/* ${TESTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TESTDIR}
	@${CHMOD} -R ${SHAREMODE} ${TESTDIR}/*
.endif

.include <bsd.port.post.mk>
