# Created by: Mita Yoshio <mita@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	lipsf
PORTVERSION=	2.00
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	http://hp.vector.co.jp/authors/VA012337/soft/lipsf/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text to LIPS filter

USES=		ncurses
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//}

PLIST_FILES=	bin/lipsf bin/pols man/ja/man1/lipsf.1.gz man/ja/man1/pols.1.gz
PORTDOCS=	HISTORY Install README TECHKNOW

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
