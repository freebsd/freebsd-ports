# New ports collection makefile for:	ines
# Date created:		02 November 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ines
PORTVERSION=	2.2
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/iNES/
DISTNAME=	iNES22-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	nakai@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
STRIP=
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ines ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ines-debug ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/ines
	@${INSTALL_DATA} ${WRKSRC}/iNES.html ${PREFIX}/share/ines
	@${INSTALL_DATA} ${WRKSRC}/CART.NES ${PREFIX}/share/ines

.include <bsd.port.post.mk>
