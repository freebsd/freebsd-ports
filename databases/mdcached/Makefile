PORTNAME=	mdcached
PORTVERSION=	1.0.9
PORTREVISION=	2
CATEGORIES=	databases net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ivoras@FreeBSD.org
COMMENT=	High performance cache server similar to memcached
WWW=		https://mdcached.sourceforge.net/

LICENSE=	BSD2CLAUSE

USES=		tar:tgz
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}

PORTDOCS=	UserGuide.txt mdcached.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=dynamic-exception-spec
.endif

post-patch:
	@${REINPLACE_CMD} 's|ADDCFLAGS = -Wall -g -O3|ADDCFLAGS = ${CFLAGS}|' \
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
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/FreeBSD/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/rc.d
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
