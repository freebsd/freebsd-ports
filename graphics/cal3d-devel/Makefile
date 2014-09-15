# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	cal3d
PORTVERSION=	20060720
PORTREVISION=	4
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	acm/${PORTNAME}
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Skeletal based 3D character animation library written in C++ (devel)

CONFLICTS=	cal3d-[0-9]*

USES=		libtool pathfix pkgconfig tar:bzip2
PATHFIX_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
AUTOMAKE_ARGS=	--add-missing
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|<istream>|<iostream>|' \
		${WRKSRC}/src/cal3d/buffersource.h \
		${WRKSRC}/src/cal3d/loader.h \
		${WRKSRC}/src/cal3d/streamsource.h
	@${REINPLACE_CMD} -e '/^all_libraries/d' ${WRKSRC}/src/cal3d/Makefile.am

.include <bsd.port.mk>
