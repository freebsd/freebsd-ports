# New ports collection makefile for:	atlast
# Date created:				26 Aug 97
# Whom:					Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	atlast
PORTVERSION=	1.2
CATEGORIES=	lang
MASTER_SITES=	http://www.fourmilab.ch/atlast/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Autodesk Threaded Language Application System Toolkit

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	atlast.html atlast.pdf

post-patch:
	${REINPLACE_CMD} -e "/^COPTIONS = /s, = .*, = ${CFLAGS}, " \
		-e "/^CC = /s,= .*, = ${CC}," \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
