# New ports collection makefile for:   shntool
# Date created:        2 November 2000
# Whom:                Bill Fenner <fenner@FreeBSD.Org>
#
# $FreeBSD$
#

PORTNAME=	shntool
PORTVERSION=	0.95
CATEGORIES=	audio
MASTER_SITES=	http://sdf.lonestar.org/~jason/shn-utils/shntool/
EXTRACT_SUFX=	.c

MAINTAINER=	fenner@FreeBSD.Org

RUN_DEPENDS=	shorten:${PORTSDIR}/audio/shorten

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} -o shntool ${DISTFILES}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shntool ${PREFIX}/bin
	${LN} -sf shntool ${PREFIX}/bin/shnlen
	${LN} -sf shntool ${PREFIX}/bin/fixwav

.include <bsd.port.mk>
