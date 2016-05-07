# Created by: nkazushi@highway.or.jp
# $FreeBSD$

PORTNAME=	plain2
PORTVERSION=	2.54.1
PORTREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	LOCAL/hrs
DISTNAME=	${PORTNAME}_${PORTVERSION:R}p${PORTVERSION:E}.orig

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}_${PORTVERSION:R}p${PORTVERSION:E}-4.2.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	TsurutaniNaoki@gmail.com
COMMENT=	Text converter from plain to any format

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}p${PORTVERSION:E}.orig
BUILD_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:R}p${PORTVERSION:E}.orig/src
PLIST_FILES=	bin/plain2
PORTDATA=	OHP.p2 OHP_t.p2 header.p2 header_t.p2 jbook.p2 supsnum.p2

CFLAGS+=	-DBSD -DKANJI -DPICTURE -DHTML -Wno-return-type
ALL_TARGET=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/lib/plain2|${DATADIR}|g' ${BUILD_WRKSRC}/plain2.h

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/*.p2 ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
