# New ports collection makefile for:	cal3d
# Date created:				12 Jul 2004
# Whom:					Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	cal3d
PORTVERSION=	0.11.0
PORTREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	http://download.gna.org/cal3d/sources/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Skeletal based 3D character animation library written in C++

CONFLICTS=	cal3d-devel-[0-9]*

USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake autoheader libtool
USE_LDCONFIG=	yes
AUTOTOOLSFILES=	aclocal.m4

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

post-configure:
	@${FIND} ${WRKSRC} -name Makefile -print | \
		${XARGS} ${REINPLACE_CMD} -e 's|MKDIR_P|mkdir_p|g'

.include <bsd.port.mk>
