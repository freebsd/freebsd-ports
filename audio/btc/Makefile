# Created by: Bill Fumerola <billf@chimesnet.com>
# $FreeBSD$

PORTNAME=	btc
PORTVERSION=	258
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for creating bass tablature

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/btc
PORTDOCS=	btc.doc

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.doc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
