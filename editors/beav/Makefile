# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beav
PORTVERSION=	1.40.18
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION:R}.orig

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Binary Editor And Viewer, a full featured binary file editor

USES=		ncurses
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R:S/.//}
ALL_TARGET=	beav
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DUNIX -DBSD -DNOPROTO"

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|(OFILES):|$$(OFILES):|' \
		-e 's|-lncurses|${LDFLAGS} -lncurses|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/beav.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/beav ${STAGEDIR}${PREFIX}/bin/beav
	${INSTALL_MAN} ${WRKSRC}/beav.1 ${STAGEDIR}${MANPREFIX}/man/man1/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/beav140.txt ${STAGEDIR}${DOCSDIR}/beav.txt

.include <bsd.port.mk>
