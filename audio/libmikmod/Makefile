# Created by: Michael Haro <mharo@area51.fremont.ca.us>
# $FreeBSD$

PORTNAME=	libmikmod
PORTVERSION=	3.1.16
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/mikmod/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	neuroworker@gmail.com
COMMENT=	MikMod Sound Library

LICENSE=	LGPL21

USES=		gmake libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-esd
USE_LDCONFIG=	yes

INFO=		mikmod

.include <bsd.port.mk>
