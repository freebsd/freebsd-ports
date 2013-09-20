# Created by: Devon H. O'Dell <devon.odell@coyotepoint.com>
# $FreeBSD$

PORTNAME=	serialoverip
PORTVERSION=	1.0
CATEGORIES=	comms net
MASTER_SITES=	CSME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transport of serial interfaces over UDP/IP

PLIST_FILES=	sbin/${PORTNAME}

NO_STAGE=	yes
do-build:
	@cd ${WRKSRC}; ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/

.include <bsd.port.mk>
