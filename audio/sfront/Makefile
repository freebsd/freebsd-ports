# New ports collection makefile for:	sfront
# Date created:				Nov 4, 2001
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	sfront
PORTVERSION=	0.89
CATEGORIES=	audio
MASTER_SITES=	http://critical.ch/distfiles/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A translator that converts MP4-SA files into efficient C programs

PORTDOCS=	book sfman

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USE_BISON=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sfront ${PREFIX}/bin
	${CP} -R ${WRKDIR}/sfront/examples/ ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for d in ${PORTDOCS}
	${CP} -R ${WRKDIR}/sfront/${d} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
