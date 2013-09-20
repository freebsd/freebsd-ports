# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ucpp
PORTVERSION=	1.3.2
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	crees@FreeBSD.org
COMMENT=	A C preprocessor and lexer

LICENSE=	BSD

MAN1=		ucpp.1
PLIST_FILES=	bin/ucpp
USE_GMAKE=	yes

WRKSRC= ${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
