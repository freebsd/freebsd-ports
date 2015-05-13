# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	pigz
PORTVERSION=	2.3.3
CATEGORIES=	archivers
MASTER_SITES=	http://www.zlib.net/pigz/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Parallel GZIP

USES=		cpe gmake
CPE_VENDOR=	zlib
MAKE_FLAGS+=	ZOPFLI=zopfli/src/zopfli/

PLIST_FILES=	bin/pigz bin/pigzn bin/pigzt bin/unpigz
PLIST_FILES+=	man/man1/pigz.1.gz

post-patch:
	${REINPLACE_CMD} -e 's/ -lz/ -lm -lz/g' ${WRKSRC}/Makefile

do-install:
.for FILE in pigz pigzn pigzt unpigz
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/pigz.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
