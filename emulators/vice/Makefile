# New ports collection makefile for:	vice
# Date created:		Mar 28, 1998
# Whom:			dchapes@ddm.on.ca
#
# $FreeBSD$

PORTNAME=	vice
PORTVERSION=	1.6
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.funet.fi/pub/cbm/crossplatform/emulators/VICE/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

USE_XLIB=	yes
RESTRICTED=	ROMs are copyrighted by Commodore Business Machines
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xaw3d

MAN1=		vice.1 c1541.1 petcat.1
MLINKS=		vice.1 x64.1 \
		vice.1 x128.1 \
		vice.1 xvic.1 \
		vice.1 xpet.1 \
		vice.1 xcbm2.1

post-install:
	@${LN} -sf vice_toc.html ${PREFIX}/share/doc/vice/index.html

.include <bsd.port.mk>
