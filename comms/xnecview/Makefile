# Created by: Søren Straarup <xride@x12.dk>
# $FreeBSD$

PORTNAME=	xnecview
PORTVERSION=	1.36
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://wwwhome.cs.utwente.nl/%7Eptdeboer/ham/xnecview/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	X11 viewer of NEC2 input and output data

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake gnome pkgconfig tar:tgz
USE_GNOME=	gtk20

PLIST_FILES=	bin/xnecview man/man1/xnecview.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xnecview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xnecview.man \
		${STAGEDIR}${MANPREFIX}/man/man1/xnecview.1

.include <bsd.port.mk>
