# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	cal3d
PORTVERSION=	0.11.0
PORTREVISION=	3
CATEGORIES=	graphics devel
MASTER_SITES=	http://download.gna.org/cal3d/sources/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Skeletal based 3D character animation library written in C++

CONFLICTS=	cal3d-devel-[0-9]*

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|<istream>|<iostream>|' \
		${WRKSRC}/src/cal3d/buffersource.h \
		${WRKSRC}/src/cal3d/loader.h \
		${WRKSRC}/src/cal3d/streamsource.h
	@${REINPLACE_CMD} '/^SUBDIRS =/s/tests//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
