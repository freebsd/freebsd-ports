# Created by: Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	whirlgif
PORTVERSION=	3.04
CATEGORIES=	graphics
MASTER_SITES=	http://archive.debian.org/debian-archive/pool/non-free/w/whirlgif/
DISTNAME=	whirlgif_3.04.orig

MAINTAINER=	hans@nordhaug.priv.no
COMMENT=	A tool for making GIF animations

WRKSRC=		${WRKDIR}/whirlgif-3.04.orig

MAN1=		whirlgif.1
PLIST_FILES=	bin/whirlgif

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whirlgif ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/whirlgif.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
