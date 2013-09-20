# Created by: Hardy Schumacher <hardy.schumacher@gmx.de>
# $FreeBSD$

PORTNAME=	z80ex
PORTVERSION=	1.1.20.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/1.1.20rev1
DISTNAME=	${PORTNAME}-1.1.20rev1

MAINTAINER=	hardy.schumacher@gmx.de
COMMENT=	ZiLOG Z80 CPU emulator library

USE_GMAKE=	yes
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's/$$(TOOLS_PREFIX)gcc/$${CC}/' \
		-e 's/$$(TOOLS_PREFIX)ar/$${AR}/' \
		-e 's/-O2//' ${WRKSRC}/Makefile

.include <bsd.port.mk>
