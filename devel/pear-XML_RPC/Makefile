# Ports collection makefile for:  pear-XML_RPC
# Date created:			  4 October 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	XML_RPC
DISTVERSION=	1.2.0RC2
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PHP implementation of the XML-RPC protocol

USE_PHP=	yes
WANT_PHP_PEAR=	yes

CATEGORY=	XML
FILES=		RPC.php RPC/Server.php RPC/Dump.php

post-extract:
	@${MKDIR} ${WRKSRC}/RPC
	@${MV} ${WRKSRC}/Server.php ${WRKSRC}/Dump.php ${WRKSRC}/RPC

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
