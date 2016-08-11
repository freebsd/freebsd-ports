# Created by: jkoshy
# $FreeBSD$

PORTNAME=	funnelweb
PORTVERSION=	3.2
CATEGORIES=	devel
MASTER_SITES=	http://www.ross.net/funnelweb/download/funnelweb_v320/
DISTNAME=	funnelweb_v320_source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful literate-programming macro pre-processor

PLIST_FILES=	bin/fw
WRKSRC=		${WRKDIR}/fw_src/source

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -c *.c && ${CC} ${CFLAGS} -o fw *.o)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fw ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
