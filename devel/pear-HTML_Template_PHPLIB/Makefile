# Ports collection makefile for:  pear-HTML_Template_PHPLIB
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Template_PHPLIB
PORTVERSION=	1.3.1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR template API ported from PHPLIB

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

TESTDIR=	${PEARDIR}/tests/${PORTNAME}

do-install:
	@${MKDIR} ${PEARDIR}/HTML/Template
	@${CP} -p ${WRKSRC}/PHPLIB.php ${PEARDIR}/HTML/Template
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/HTML/Template/PHPLIB.php
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -Rp ${WRKSRC}/examples/* ${DOCSDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${ECHO_MSG} "===> Examples installed in ${DOCSDIR}."
	@${ECHO_MSG} "     (These tests require PEAR::Benchmark - see"
	@${ECHO_MSG} "     <http://pear.php.net/package-info.php?package=Benchmark>;;;)."
.endif

.include <bsd.port.post.mk>
