# New ports collection makefile for: wordplay
# Date created:		24 Jun 2000
# Whom:			Ben Smithurst <ben@scientia.demon.co.uk>
#
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
PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/words721.txt
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|"words721.txt"|"${DATADIR}/words721.txt"| ; \
		 s|<ctype.h>|<stdlib.h>|' ${WRKSRC}/wordplay.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/words721.txt ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.mk>
