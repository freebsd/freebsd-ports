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

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Extract/decompress CP/M LBR archives

MAKE_ARGS=	CC="${CC}" CFLAGS="${CPPFLAGS} ${CFLAGS} ${LDFLAGS}"

MAN1=		lbrate.1
PORTDOCS=	ChangeLog README TODO
PLIST_FILES=	bin/lbrate

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lbrate ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lbrate.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
