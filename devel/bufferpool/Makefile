# Created by: Emmanuel Richiardone (err@tollari.org)
# $FreeBSD$

PORTNAME=	bufferpool
PORTVERSION=	0.0.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://lscube.org/files/downloads/bufferpool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bufferpool - the memory management library Feng and Felix depend upon

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig tar:bzip2

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libbufferpool.so

.include <bsd.port.mk>
