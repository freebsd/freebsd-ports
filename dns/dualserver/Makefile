# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	dualserver
PORTVERSION=	7.01
CATEGORIES=	dns net
MASTER_SITES=	SF/dhcp-dns-server/Dual%20DHCP%20DNS%20Server/ \
		http://rodrigo.osorio.free.fr/freebsd/distfiles/
DISTNAME=	${PORTNAME}V${PORTVERSION}

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Combined DHCP/DNS server for small LANs

USE_DOS2UNIX=	yes
USE_RC_SUBR=	dualserver
PLIST_FILES=	sbin/dualserver etc/dualserver.conf.sample

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

do-build:
	${CXX} ${CXXFLAGS} -o ${WRKSRC}/dualserver \
		${WRKSRC}/dualserverd.cpp ${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ini \
		${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
