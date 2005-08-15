# Ports collection makefile for:  pear-XML_RPC
# Date created:			  4 October 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	XML_RPC
PORTVERSION=	1.4.0
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PHP implementation of the XML-RPC protocol

USE_PHP=	yes
WANT_PHP_PEAR=	yes

CATEGORY=	XML
FILES=		RPC.php RPC/Server.php RPC/Dump.php
TESTS=		protoport.php test_Dump.php

post-extract:
	@${MKDIR} ${WRKSRC}/RPC
	@${MV} ${WRKSRC}/Server.php ${WRKSRC}/Dump.php ${WRKSRC}/RPC

post-patch:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" ${WRKSRC}/${file}
.endfor
.for file in ${TESTS}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" ${WRKSRC}/tests/${file}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
