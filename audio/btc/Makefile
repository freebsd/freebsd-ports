# New ports collection makefile for:   btc
# Date created:        1 August 2000
# Whom:                Bill Fumerola <billf@chimesnet.com>
#
# $FreeBSD$
#

PORTNAME=	btc
PORTVERSION=	258
CATEGORIES=	audio
MASTER_SITES=	http://www.harmony-central.com/Bass/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	billf@FreeBSD.org
COMMENT=	A tool for creating bass tablature

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/btc
PORTDOCS=	btc.doc

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
