# Created by: jkoshy
# $FreeBSD$

PORTNAME=	funnelweb
PORTVERSION=	3.2
CATEGORIES=	devel
MASTER_SITES=	http://www.ross.net/funnelweb/download/funnelweb_v320/
DISTNAME=	funnelweb_v320_source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A powerful literate-programming macro pre-processor

PLIST_FILES=	bin/fw
WRKSRC=		fw_src/source

NO_STAGE=	yes
do-build:
	cd ${WRKDIR}/${WRKSRC} && { \
		${CC} ${CFLAGS} -c *.c && \
		${CC} ${CFLAGS} -o fw *.o; \
		}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${WRKSRC}/fw ${PREFIX}/bin

.include <bsd.port.mk>
