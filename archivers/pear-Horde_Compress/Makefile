# Ports collection makefile for:  pear-Horde_Compress
# Date created:			  6 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	Horde_Compress
PORTVERSION=	1.0.4
CATEGORIES=	archivers www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Compression API

OPTIONS=	ZLIB "Depend on PHP zlib extension" On

USE_HORDE_RUN=	Horde_Exception Horde_Translation Horde_Util Horde_Stream_Filter

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ZLIB)
USE_PHP+=	zlib
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
