# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beav
PORTVERSION=	1.40.18
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION:R}.orig

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Binary Editor And Viewer, a full featured binary file editor

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R:S/.//}

ALL_TARGET=	beav
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DUNIX -DBSD -DNOPROTO"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/beav ${STAGEDIR}${PREFIX}/bin/beav
	${INSTALL_MAN} ${WRKSRC}/beav.1 ${STAGEDIR}${PREFIX}/man/man1/beav.1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/beav140.txt ${STAGEDIR}${DOCSDIR}/beav.txt
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    ${STAGEDIR}${PREFIX}/man/man1/beav.1

.include <bsd.port.mk>
