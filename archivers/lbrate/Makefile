# New ports collection makefile for:	lbrate
# Date created:			26 August 2001
# Whom:				Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	lbrate
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extract/decompress CP/M LBR archives

USE_GETOPT_LONG=	yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		lbrate.1
PORTDOCS=	${DOC_FILES}
PLIST_FILES=	bin/lbrate

DOC_FILES=	ChangeLog README TODO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lbrate ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lbrate.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
