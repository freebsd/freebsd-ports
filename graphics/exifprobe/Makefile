# New ports collection makefile for:	exifprobe
# Date created:		2004-07-21
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	exifprobe
PORTVERSION=	1.2.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.monroe.net/~dhh/exifprobe.d/

MAINTAINER=	ahze@ahze.net
COMMENT=	Probes JPEG or TIFF images and reports contents and structure

USE_REINPLACE=	yes

MAN1=		exifgrep.1 exifprobe.1
PORTDOCS=	DESCRIPTION exifprobe-rman.html
PLIST_FILES=	bin/exifgrep bin/exifprobe

post-patch:
	@${REINPLACE_CMD} -e 's|cc|${CC}|; s|-DC|${CFLAGS} -DC|' \
		 ${WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/exifgrep ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/exifprobe ${PREFIX}/bin
.for i in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${i} ${MANPREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
