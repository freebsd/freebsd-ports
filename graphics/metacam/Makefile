# New ports collection makefile for:	metacam
# Date created:				2 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	metacam
PORTVERSION=	1.2
CATEGORIES=	graphics
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A digital camera EXIF meta-information reader

USE_GMAKE=	yes

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/metacam
PORTDOCS=	README.canon README.casio
MAN1=		metacam.1

ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
