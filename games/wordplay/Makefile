# Created by: Ben Smithurst <ben@scientia.demon.co.uk>
# $FreeBSD$

PORTNAME=	wordplay
PORTVERSION=	7.22
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://hsvmovies.com/static_subpages/personal_orig/wordplay/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple program to generate anagrams

NO_WRKSUBDIR=	yes

PORTDOCS=	readme

PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/words721.txt
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC?=g++|' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's|"words721.txt"|"${DATADIR}/words721.txt"| ; \
		 s|<ctype.h>|<stdlib.h>|' ${WRKSRC}/wordplay.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/words721.txt ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
