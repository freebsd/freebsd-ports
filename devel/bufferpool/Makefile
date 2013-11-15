# Created by: Emmanuel Richiardone (err@tollari.org)
# $FreeBSD$

PORTNAME=	bufferpool
PORTVERSION=	0.0.4
CATEGORIES=	devel
MASTER_SITES=	http://lscube.org/files/downloads/bufferpool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bufferpool - the memory management library Feng and Felix depend upon

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=	gmake pathfix pkgconfig

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libbufferpool.so.4

.include <bsd.port.mk>
