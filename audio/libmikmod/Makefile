# Created by: Michael Haro <mharo@area51.fremont.ca.us>
# $FreeBSD$

PORTNAME=	libmikmod
PORTVERSION=	3.3.8
CATEGORIES=	audio
MASTER_SITES=	SF/mikmod/libmikmod/${PORTVERSION}/

MAINTAINER=	neuroworker@gmail.com
COMMENT=	MikMod Sound Library

LICENSE=	LGPL21

USES=		cpe gmake libtool pkgconfig
CPE_VENDOR=	raphael_assenat
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-esd
USE_LDCONFIG=	yes

INFO=		mikmod

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.3.3.0

.include <bsd.port.mk>
