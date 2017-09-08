# $FreeBSD$

PORTNAME=	Horde_Compress
PORTVERSION=	2.2.1
CATEGORIES=	archivers www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Compression API

OPTIONS_DEFAULT=	ZLIB
OPTIONS_DEFINE=		ZLIB
ZLIB_DESC=	Depend on PHP zlib extension

USES=	horde
USE_HORDE_RUN=	Horde_Exception \
		Horde_Translation \
		Horde_Util \
		Horde_Stream_Filter

ZLIP_USE=	PHP=zlib

.include <bsd.port.mk>
