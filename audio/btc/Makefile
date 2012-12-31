# Created by: Bill Fumerola <billf@chimesnet.com>
# $FreeBSD$

PORTNAME=	btc
PORTVERSION=	258
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for creating bass tablature

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/btc
PORTDOCS=	btc.doc

.include <bsd.port.options.mk>

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
