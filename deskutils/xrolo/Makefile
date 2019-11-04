# Created by: Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
# $FreeBSD$

PORTNAME=	xrolo
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp.uni-potsdam.de/pub/X11/open-look/ \
		ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/
DISTNAME=	${PORTNAME}.v2p6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic Rolodex

LIB_DEPENDS=	libxview.so:x11-toolkits/xview

WRKSRC=		${WRKDIR}/xrolo

USES=		imake tar:Z xorg
USE_XORG=	x11 xext
PLIST_FILES=	bin/xrolo man/man1/xrolo.1.gz

CFLAGS+=	-Wno-return-type

post-configure:
	@${REINPLACE_CMD} 's|DESTDIR) |DESTDIR)|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
