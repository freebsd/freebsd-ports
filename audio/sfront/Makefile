# ex:ts=8
# New ports collection makefile for:	sfront
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sfront
PORTVERSION=	0.88
CATEGORIES=	audio
MASTER_SITES=	http://www.cs.berkeley.edu/~lazzaro/sa/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A translator that converts MP4-SA files into efficient C programs

.if !defined(NOPORTDOCS)
PORTDOCS=	book sfman
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USE_BISON=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sfront ${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKDIR}/sfront/sfman ${DOCSDIR}/
	${CP} -R ${WRKDIR}/sfront/book ${DOCSDIR}/
.endif
	${CP} -R ${WRKDIR}/sfront/examples/ ${EXAMPLESDIR}

.include <bsd.port.mk>
