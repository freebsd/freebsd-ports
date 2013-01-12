# Created by: Hardy Schumacher <hardy.schumacher@gmx.de>
# $FreeBSD$

PORTNAME=	z80ex
PORTVERSION=	1.1.20
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	hardy.schumacher@gmx.de
COMMENT=	ZiLOG Z80 CPU emulator library

USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/$$(TOOLS_PREFIX)gcc/$${CC}/' \
		-e 's/$$(TOOLS_PREFIX)ar/$${AR}/' \
		-e 's/-O2//' ${WRKSRC}/Makefile

.include <bsd.port.mk>
