# New ports collection makefile for:	plain2
# Date created:		20 April 1997
# Whom:			nkazushi@highway.or.jp
#
# $FreeBSD$
#

PORTNAME=	plain2
PORTVERSION=	2.54.1
PORTREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	http://ftp.debian.or.jp/debian-jp/pool/main/p/plain2/
DISTNAME=	${PORTNAME}_${PORTVERSION:R}p${PORTVERSION:E}.orig

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}_${PORTVERSION:R}p${PORTVERSION:E}-4.2.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A text converter from plain to any format

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}p${PORTVERSION:E}.orig
BUILD_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:R}p${PORTVERSION:E}.orig/src

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DBSD -DKANJI -DPICTURE -DHTML -fwritable-strings"
ALL_TARGET=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/lib/plain2|${DATADIR}|g' ${BUILD_WRKSRC}/plain2.h

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/*.p2 ${DATADIR}

.include <bsd.port.mk>
