# Ports collection makefile for:  pear-HTML_Template_PHPLIB
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Template_PHPLIB
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR template API ported from PHPLIB

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML/Template
FILES=		PHPLIB.php
DOCS=		README
EXAMPLES=	block.ihtml block.php ittest.php tpl1.ihtml tpl1.php
_DOCSDIR=	examples

do-install-tests-msg: .USE
	@${ECHO_MSG} "     (These tests require PEAR::Benchmark - see"
	@${ECHO_MSG} "     <http://pear.php.net/package-info.php?package=Benchmark>;;;)."

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
