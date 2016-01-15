# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deutex
PORTVERSION=	4.4.0
PORTREVISION=	1
CATEGORIES=	archivers games
MASTER_SITES=	http://www.teaser.fr/~amajorel/deutex/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WAD file manipulator for Doom, Heretic, Hexen, and Strife

LICENSE=	GPLv2 LGPL20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/deusf bin/deutex \
		man/man6/${PORTNAME}.6.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${REINPLACE_CMD} -e 's,-mkdir,mkdir -p,' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,malloc\.h,stdlib.h,' ${WRKSRC}/src/tools.c
	@${REINPLACE_CMD} -e '/blockv/s,VOCHEAD,VOCBLOCK1,' \
		${WRKSRC}/src/sound.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deusf ${WRKSRC}/deutex \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dtexman6.txt ${STAGEDIR}${DOCSDIR}/MANUAL

.include <bsd.port.mk>
