# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ucpp
PORTVERSION=	1.3.2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	crees@FreeBSD.org
COMMENT=	C preprocessor and lexer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GH_ACCOUNT=	lpsantil
GH_TAGNAME=	31b719e
USE_GITHUB=	yes

PLIST_FILES=	bin/ucpp man/man1/ucpp.1.gz
USES=		gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
