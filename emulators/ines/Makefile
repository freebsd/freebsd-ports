# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	ines
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/iNES/
DISTNAME=	iNES30-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nintendo Entertainment System emlator for X

LIB_DEPENDS=	libc.so.5:misc/compat5x

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	is an i386 binary

NO_WRKSUBDIR=	yes
USE_XORG=	x11 xext
NO_BUILD=	yes
STRIP=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ines ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} iNES.html CART.NES *.pal \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
