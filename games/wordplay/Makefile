# Created by: Ben Smithurst <ben@scientia.demon.co.uk>
# $FreeBSD$

PORTNAME=	wordplay
PORTVERSION=	7.22
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://hsvmovies.com/static_subpages/personal_orig/wordplay/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple program to generate anagrams

NO_WRKSUBDIR=	yes

PORTDOCS=	readme
OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/words721.txt
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC?=g++|' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's|"words721.txt"|"${DATADIR}/words721.txt"| ; \
		 s|<ctype.h>|<stdlib.h>|' ${WRKSRC}/wordplay.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/words721.txt ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
