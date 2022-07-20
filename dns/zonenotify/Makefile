PORTNAME=	zonenotify
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.morettoni.net/bsd/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	DNS notify sender written in C

PLIST_FILES=	bin/zonenotify
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${STAGEDIR}${PREFIX}|' \
		${WRKSRC}/Makefile

do-build:
	${CC} -o ${WRKSRC}/${PORTNAME} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
