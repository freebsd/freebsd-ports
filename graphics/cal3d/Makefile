# New ports collection makefile for:	cal3d
# Date created:				12 Jul 2004
# Whom:					Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	cal3d
PORTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	http://download.gna.org/cal3d/sources/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Skeletal based 3d character animation library written in C++

CONFLICTS=	cal3d-devel-[0-9]*

USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:19 autoheader:262 libtool:22
USE_LDCONFIG=	yes

MAN1=	cal3d_converter.1

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^\(pkgconfigdir\ =\).*|\1 $$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|<istream>|<iostream>|' \
		${WRKSRC}/src/cal3d/buffersource.h \
		${WRKSRC}/src/cal3d/loader.h \
		${WRKSRC}/src/cal3d/streamsource.h
	@${REINPLACE_CMD} -e '/^all_libraries/d' ${WRKSRC}/src/cal3d/Makefile.am

.include <bsd.port.mk>
