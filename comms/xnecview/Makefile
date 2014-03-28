# Created by: Søren Straarup <xride@x12.dk>
# $FreeBSD$

PORTNAME=	xnecview
PORTVERSION=	1.36
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://wwwhome.cs.utwente.nl/%7Eptdeboer/ham/xnecview/
EXTRACT_SUFX=	.tgz

MAINTAINER=	xride@FreeBSD.org
COMMENT=	A X viewer of nec2c data

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png
RUN_DEPENDS=	nec2c:${PORTSDIR}/comms/nec2c

USES=		gmake pkgconfig
USE_GNOME=	gtk20

PLIST_FILES=	bin/xnecview man/man1/xnecview.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xnecview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xnecview.man \
		${STAGEDIR}${MANPREFIX}/man/man1/xnecview.1

.include <bsd.port.mk>
