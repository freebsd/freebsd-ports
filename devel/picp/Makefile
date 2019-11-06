# Created by: Bruce M Simpson <bms@spc.org>
# $FreeBSD$

PORTNAME=	picp
PORTVERSION=	0.6.8
CATEGORIES=	devel
MASTER_SITES=	http://home.pacbell.net/theposts/picmicro/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Driver for the Microchip Picstart Plus development programmer

BROKEN=		unfetchable

PLIST_FILES=	bin/picp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picp ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
