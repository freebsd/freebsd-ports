# Created by: ivoras
# $FreeBSD$

PORTNAME=	sqlcached
PORTVERSION=	r6
PORTREVISION=	3
CATEGORIES=	databases net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ivoras@FreeBSD.org
COMMENT=	Cache daemon using SQL for data manipulation

USES=		localbase:ldflags ncurses readline sqlite tar:tgz

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	${PORTNAME}.html ${PORTNAME}.txt

PLIST_FILES=	bin/${PORTNAME} etc/rc.d/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/FreeBSD/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/FreeBSD/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/rc.d
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
