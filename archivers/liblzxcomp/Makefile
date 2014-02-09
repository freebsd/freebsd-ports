# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	liblzxcomp
PORTVERSION=	20050705
CATEGORIES=	archivers
MASTER_SITES=	http://www.russotto.net/chm/
DISTNAME=	lzx_compress

MAINTAINER=	ak@FreeBSD.org
COMMENT=	LZX compression library

USES=	uidfix
USE_LDCONFIG=	yes

post-patch:
	@${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -i '' -e 's|stdint|sys/types|' \
		${WRKSRC}/lzx_compress.mdoc3 ${WRKSRC}/lzx_layer.c
	@${MV} ${WRKSRC}/lzx_compress.mdoc3 ${WRKSRC}/lzxcomp.3

.include <bsd.port.mk>
