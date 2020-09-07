# $FreeBSD$

PORTNAME=	librs232
PORTVERSION=	20190531
CATEGORIES=	comms
DISTNAME=	RS-232
MASTER_SITES=	http://www.teuniz.net/RS-232/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple serial library

LICENSE=	GPLv3
LICENSE_FILE=   ${WRKSRC}/gpl.txt

WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		uidfix
USE_LDCONFIG=	yes

PORTEXAMPLES=	demo_rx.c demo_tx.c

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
