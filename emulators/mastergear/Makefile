# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	mastergear
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/MG/
DISTNAME=	MG20-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SEGA Master System and Game Gear emulator for X

LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x

NO_WRKSUBDIR=	yes
ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
STRIP=

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CART.ROM ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/SF7000.ROM ${DATADIR}
.if(!defined(NOPORTDOCS))
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MG.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
