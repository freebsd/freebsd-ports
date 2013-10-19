# Created by: ijliao
# $FreeBSD$

PORTNAME=	exiftags
PORTVERSION=	1.01
CATEGORIES=	graphics
MASTER_SITES=	http://johnst.org/sw/exiftags/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Parses a specified JPEG file for a JPEG APP1 section containing Exif data

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}"

DOCS=	CHANGES README

do-install:
.for i in exifcom exiftags exiftime
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${i}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in CHANGES README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
