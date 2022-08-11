PORTNAME=	lzmalib
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://tokyocabinet.sourceforge.net/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Thin wrapper library of LZMA

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lzmacmd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblzma.so

.include <bsd.port.mk>
