# Ports collection makefile for:  pear-HTML_Template_IT
# Date created:			  02 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Template_IT
PORTVERSION=	1.1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR template API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

MANIFEST=	IT.php ITX.php IT_Error.php
TESTDIR=	${PEARDIR}/tests/${PORTNAME}

do-install:
	@${MKDIR} -p ${PEARDIR}/HTML/Template
.for FILE in ${MANIFEST}
	@${CP} -p ${WRKSRC}/${FILE} ${PEARDIR}/HTML/Template
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/HTML/Template
.if !defined(NOPORTDOCS)
	@${MKDIR} ${TESTDIR}
	@${CP} -Rp ${WRKSRC}/tests/* ${TESTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TESTDIR}
	@${ECHO_MSG} "===> Examples installed in ${TESTDIR}."
	@${ECHO_MSG} "     (These tests require PHPUnit - see"
	@${ECHO_MSG} "     <http://pear.php.net/package-info.php?package=PHPUnit>;;)."
.endif

.include <bsd.port.post.mk>
