# Created by: Roger Hardiman <roger@freebsd.org>
# $FreeBSD$

PORTNAME=	vid
PORTVERSION=	1.0.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/ovt${PORTNAME}-bsd/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	olivier@gid0.org
COMMENT=	Grab images from USB Cameras using the OV511 and OV511+ chipset

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05

LIB_DEPENDS=	netpbm:${PORTSDIR}/graphics/netpbm

PLIST_FILES=	bin/vid

# The port does not understand 'make all' or 'make install'
# so change the 'all_target' to be empty and use our own do-install handler.
ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vid ${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
