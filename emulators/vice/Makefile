# New ports collection makefile for:	vice
# Version required:	1.0
# Date created:		Mar 28, 1998
# Whom:			dchapes@ddm.on.ca
#
# $FreeBSD$

DISTNAME=	vice-1.0
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.funet.fi/pub/cbm/crossplatform/emulators/VICE/

MAINTAINER=	dchapes@ddm.on.ca

LIB_DEPENDS=	Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d

WRKSRC=		${WRKDIR}/vice-1.0
USE_XLIB=	yes
RESTRICTED=	ROMs are copyrighted by Commodore Business Machines
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -Wall -O5 -fomit-frame-pointer \
		-funroll-loops -finline-functions -fno-strength-reduce"
CONFIGURE_ARGS=	--with-xaw3d

MAN1=		vice.1 c1541.1 petcat.1
MLINKS=		vice.1 x64.1 \
		vice.1 x128.1 \
		vice.1 xvic.1 \
		vice.1 xpet.1 \
		vice.1 xcbm2.1

post-install:
	@${LN} -sf vice-toc.html ${PREFIX}/lib/vice/doc/index.html

.include <bsd.port.mk>
