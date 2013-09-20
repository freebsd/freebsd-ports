# Created by: ijliao
# $FreeBSD$

PORTNAME=	nomarch
PORTVERSION=	1.4
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Extracts files from the old '.arc' archive format

MAN1=	nomarch.1
NO_STAGE=	yes
PLIST_FILES=	bin/nomarch
PORTDOCS=	COPYING ChangeLog NEWS README TODO

post-patch:
	${REINPLACE_CMD} -e 's|CC=|CC?=|' \
		-e 's|CFLAGS=|CFLAGS?=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nomarch ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nomarch.1 ${MAN1PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
