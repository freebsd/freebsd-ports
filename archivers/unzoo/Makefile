# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	unzoo
PORTVERSION=	4.4
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	CRITICAL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	unzoo_4.4-4.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	ZOO archive extractor

EXTRA_DEFINES=	-DSYS_IS_UNIX -DSYS_HAS_MKDIR

PLIST_FILES=	bin/unzoo man/man1/unzoo.1.gz

CFLAGS+=	-trigraphs

post-extract:
	@${MKDIR} ${WRKSRC}
	@${MV} ${WRKDIR}/${PORTNAME}.c ${WRKSRC}

do-build:
	${CC} ${CFLAGS} ${EXTRA_DEFINES} -o ${WRKSRC}/${PORTNAME} \
		${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/debian/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
