# Ports collection makefile for:  pear-XML_Parser
# Date created:			  03 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_Parser
PORTVERSION=	1.0.1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR XML parsing class based on PHP's bundled expat

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

TESTDIR=	${PEARDIR}/tests/${PORTNAME}

do-install:
	@${MKDIR} ${PEARDIR}/XML
	@${CP} -p ${WRKSRC}/Parser.php ${PEARDIR}/XML
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/XML/Parser.php
.if !defined(NOPORTDOCS)
	@${MKDIR} ${TESTDIR}
	@${CP} -Rp ${WRKSRC}/tests/* ${TESTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TESTDIR}
	@${ECHO_MSG} "===> Examples installed in ${TESTDIR}."
	@${ECHO_MSG} "     (These tests require PHPUnit - see"
	@${ECHO_MSG} "     <http://pear.php.net/package-info.php?package=PHPUnit>;;)."
.endif

.include <bsd.port.post.mk>
