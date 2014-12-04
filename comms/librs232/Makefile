# $FreeBSD$

PORTNAME=	librs232
PORTVERSION=	20140105
CATEGORIES=	comms
DISTNAME=	RS-232
MASTER_SITES=	http://www.teuniz.net/RS-232/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Simple serial library

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}

OPTIONS_DEFINE=	DOCS

USES=		uidfix
USE_LDCONFIG=	yes

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
