# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	dualserver
PORTVERSION=	6.94
CATEGORIES=	dns net
MASTER_SITES=	SF/dhcp-dns-server/Dual%20DHCP%20DNS%20Server/
DISTNAME=	${PORTNAME}V${PORTVERSION}

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Combined DHCP/DNS server for small LANs

USE_DOS2UNIX=	yes
USE_RC_SUBR=	dualserver
PLIST_FILES=	sbin/dualserver etc/dualserver.conf.sample

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

#pre-patch:
#post-patch:
#	${REINPLACE_CMD} 's|/etc/dualserver.ini|${PREFIX}/etc/dualserver.conf|' ${WRKSRC}/dualserverd.cpp
#	${REINPLACE_CMD} 's|/etc/dualserver.state|/var/run/dualserver.state|' ${WRKSRC}/dualserverd.cpp

do-build:
	${CXX} ${CXXFLAGS} -o ${WRKSRC}/dualserver \
		${WRKSRC}/dualserverd.cpp ${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dualserver ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dualserver.ini ${PREFIX}/etc/dualserver.conf.sample

.include <bsd.port.mk>
