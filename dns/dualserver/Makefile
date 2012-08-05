# Ports collection Makefile for:	dualserver
# Date created:				10 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	dualserver
PORTVERSION=	3.0
CATEGORIES=	dns net
MASTER_SITES=	SF/dhcp-dns-server/OldFiles
DISTNAME=	${PORTNAME}V${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Combined DHCP/DNS server for small LANs

USE_DOS2UNIX=	yes
USE_RC_SUBR=	dualserver
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	sbin/dualserver etc/dualserver.conf.sample

.include <bsd.port.pre.mk>

pre-patch:
	${REINPLACE_CMD} 's|/etc/dualserver.ini|${PREFIX}/etc/dualserver.conf|' ${WRKSRC}/dualserver.cpp
	${REINPLACE_CMD} 's|/etc/dualserver.state|/var/run/dualserver.state|' ${WRKSRC}/dualserver.cpp

do-build:
	${CXX} -o ${WRKSRC}/dualserver ${WRKSRC}/dualserver.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dualserver ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dualserver.ini ${PREFIX}/etc/dualserver.conf.sample

.include <bsd.port.post.mk>
