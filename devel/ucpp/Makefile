# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ucpp
PORTVERSION=	1.3.2
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	crees@FreeBSD.org
COMMENT=	A C preprocessor and lexer

LICENSE=	BSD3CLAUSE

PLIST_FILES=	bin/ucpp man/man1/ucpp.1.gz
USES=		gmake

WRKSRC= 	${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
