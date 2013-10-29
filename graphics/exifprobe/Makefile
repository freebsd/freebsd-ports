# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	exifprobe
DISTVERSION=	2.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Probes JPEG or TIFF images and reports contents and structure

PLIST_FILES=	bin/exifgrep \
		bin/exifprobe \
		man/man1/exifgrep.1.gz \
		man/man1/exifprobe.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|cc|${CC}|; s|-DC|${CFLAGS} -DC|' \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/exifgrep ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/exifprobe ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/exifgrep.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/exifprobe.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
