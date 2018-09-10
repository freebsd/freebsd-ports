# Created by: Ivan Voras <ivoras@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mdcached
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	databases net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ivoras@FreeBSD.org
COMMENT=	High performance cache server similar to memcached

LICENSE=	BSD2CLAUSE

USES=		tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}
USE_LDCONFIG=	yes

PORTDOCS=	UserGuide.txt mdcached.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|ADDCFLAGS = -Wall -g -O3 -march=native|ADDCFLAGS = ${CFLAGS}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/FreeBSD/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf lib${PORTNAME}.so.1 ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so
	${INSTALL_DATA} ${WRKSRC}/lib${PORTNAME}.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/mc_protocol.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/mc_client.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/FreeBSD/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/rc.d
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
