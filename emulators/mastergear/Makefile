# New ports collection makefile for:   mastergear
# Date created:        02 November 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mastergear
PORTVERSION=	2.0
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/MG/
DISTNAME=	MG20-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SEGA Master System and Game Gear emulator for X

NO_WRKSUBDIR=	yes
ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
STRIP=
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CART.ROM ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/SF7000.ROM ${DATADIR}
.if(!defined(NOPORTDOCS))
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MG.html ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000 || ${OSVERSION} > 600000
IGNORE=	Does not run, wants libc.so.5
.endif


.include <bsd.port.post.mk>
