# New ports collection makefile for:	vid
# Date created:		Tue Dec  5 13:32:13 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vid
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ovtvid-bsd

MAINTAINER=	olivier@gid0.org
COMMENT=	Grab images from USB Cameras using the OV511 and OV511+ chipset

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
