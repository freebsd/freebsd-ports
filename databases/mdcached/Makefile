# New ports collection makefile for:	mdcached
# Date created:			3 February 2012
# Whom:				Ivan Voras <ivoras@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdcached
PORTVERSION=	1.0.6
CATEGORIES=	databases net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ivoras@FreeBSD.org
COMMENT=	A high performance cache server similar to memcached

LICENSE=	BSD

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}
USE_LDCONFIG=	yes
MAN1=		${PORTNAME}.1

PORTDOCS=	UserGuide.txt mdcached.txt

post-patch:
	@${REINPLACE_CMD} 's|ADDCFLAGS = -Wall -g -O3 -march=native|ADDCFLAGS = ${CFLAGS}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/FreeBSD/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so.1 ${PREFIX}/lib
	${LN} -s lib${PORTNAME}.so.1 ${PREFIX}/lib/lib${PORTNAME}.so
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/mc_protocol.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/mc_client.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/FreeBSD/${PORTNAME} ${PREFIX}/etc/rc.d

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for doc in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$${doc} ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
