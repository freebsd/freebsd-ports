# New ports collection makefile for:  sqlcached
# Date created:        3 January 2007
# Whom:                ivoras
#
# $FreeBSD$
#

PORTNAME=	sqlcached
PORTVERSION=	r4
CATEGORIES=	databases net
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ivoras@FreeBSD.org
COMMENT=	A cache daemon using SQL for data manipulation

LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite2

MAKE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib
CFLAGS=		-O2 -Wall -I${LOCALBASE}/include

WRKSRC=	${WRKDIR}/${PORTNAME}
MAN1=		${PORTNAME}.1

PORTDOCS=	${PORTNAME}.html ${PORTNAME}.txt

PLIST_FILES=	bin/${PORTNAME} etc/rc.d/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -E -e 's|^(.*FLAGS)=|\1?=|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/FreeBSD/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/FreeBSD/${PORTNAME} ${PREFIX}/etc/rc.d

.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} -m 555 ${DOCSDIR}
	for doc in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$${doc} ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
