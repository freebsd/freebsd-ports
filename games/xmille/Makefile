# Created by: swallace
# $FreeBSD$

PORTNAME=	xmille
PORTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	XCONTRIB
MASTER_SITE_SUBDIR=	games
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X window mille bourne game

WRKSRC=		${WRKDIR}/Mille

USES=		imake
USE_XORG=	x11 xext
MAN1=		xmille.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/xmille
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-Wno-error=return-type

post-extract:
	@${FIND} ${WRKSRC} -name '*.[ao]' -delete

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmille ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmille.man ${MANPREFIX}/man/man1/xmille.1

.include <bsd.port.mk>
