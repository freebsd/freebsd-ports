# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	mar
DISTVERSION=	0.5
CATEGORIES=	archivers
MASTER_SITES=	CRITICAL
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Simple binary file format for storing arbitrary meta and user data

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E "s#^(CFLAGS\ |CXXFLAGS\ |CC\ |CXX\ )#\1?#" \
		${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/mar.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
