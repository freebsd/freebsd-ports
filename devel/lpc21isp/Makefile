# Created by: Steve Franks <stevefranks@ieee.org>
# $FreeBSD$

PORTNAME=	lpc21isp
PORTVERSION=	1.64
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISP programmer tool for flashing NXP & Analog Devices ARM7 CPUs

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

MAKE_ENV=	RM="${RM}"
ALL_TARGET=	clean all

PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Respect CC, remove some apparently old and GNU make spelled conditional
	@${REINPLACE_CMD} -e '4,8d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
