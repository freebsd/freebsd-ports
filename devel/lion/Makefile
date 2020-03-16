# Created by: Marco Molteni <molterSPAM@gufiSPAM.org>
# $FreeBSD$

PORTNAME=	lion
DISTVERSION=	20060630
CATEGORIES=	devel net
MASTER_SITES=	http://www.lundman.net/ftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-platform, event-driven, simple networking library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

# TODO
# add support for SSL/TLS/OpenSSL
USES=		gmake tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	default

INCLUDES=	base64.h connections.h io.h lfnmatch.h lgroup.h lion.h \
		lion_rcsid.h lion_types.h misc.h pipe.h sockets.h \
		timers.h tls.h udp.h zlib.h

post-patch:
	@${REINPLACE_CMD} -E 's,^(CC|LDFLAGS) *=,\1 ?=,' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/liblion.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/lion
.for i in ${INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/include/lion
.endfor

.include <bsd.port.mk>
