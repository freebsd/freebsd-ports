# New ports collection makefile for:	mar
# Date created:				20 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	mar
DISTVERSION=	0.5
CATEGORIES=	archivers
MASTER_SITES=	http://www.emantic.co.uk/mark/files/ \
		http://critical.ch/mar/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A simple binary file format for storing arbitrary meta and user data

USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

MAN1=		mar.1

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CFLAGS\ \)|\1?|' \
		${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|^\(CXXFLAGS\ \)|\1?|' \
		${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/mar.1 ${MANPREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
