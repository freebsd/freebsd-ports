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

WRKSRC=		${WRKDIR}

do-build:

	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:

	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.doc \
	 ${PREFIX}/share/doc/${PORTNAME}

.include <bsd.port.mk>
