# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deutex
PORTVERSION=	4.4.0
PORTREVISION=	1
CATEGORIES=	archivers games
MASTER_SITES=	http://www.teaser.fr/~amajorel/deutex/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	WAD file manipulator for Doom, Heretic, Hexen, and Strife

LICENSE=	GPLv2

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

NO_STAGE=	yes
MAN6=		${PORTNAME}.6
PLIST_FILES=	bin/deusf bin/deutex
PORTDOCS=	*

post-extract:
	@${REINPLACE_CMD} -e 's,-mkdir,mkdir -p,' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,malloc\.h,stdlib.h,' ${WRKSRC}/src/tools.c
	@${REINPLACE_CMD} -e '/blockv/s,VOCHEAD,VOCBLOCK1,' \
		${WRKSRC}/src/sound.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deusf ${WRKSRC}/deutex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MANPREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/TODO ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dtexman6.txt ${DOCSDIR}/MANUAL
.endif

.include <bsd.port.mk>
