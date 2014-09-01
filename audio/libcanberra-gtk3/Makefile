# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/libcanberra-gtk3/Makefile,v 1.8 2011/03/16 10:24:48 kwm Exp $

CATEGORIES=	audio devel
PKGNAMESUFFIX=	-gtk3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec

MASTERDIR=	${.CURDIR}/../../audio/libcanberra
SLAVEPORT=	gtk3
PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	libcanberra-gtk3.la libcanberra-gtk3-module.la

pre-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} libcanberra-gtk3.pc

do-install:
	${INSTALL_DATA} ${WRKSRC}/libcanberra-gtk3.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/
.for i in .so .so.0 .so.0.1.8
	${INSTALL_LIB} ${WRKSRC}/src/.libs/libcanberra-gtk3${i} \
		${STAGEDIR}${PREFIX}/lib/
.endfor
	cd ${WRKSRC}/src && ${SETENV} DESTDIR=${STAGEDIR} \
		${MAKE_CMD} install-gtk3moduleLTLIBRARIES
	cd ${STAGEDIR}${PREFIX}/lib/gtk-3.0/modules && \
		${LN} -sf libcanberra-gtk3-module.so libcanberra-gtk-module.so

.include "${MASTERDIR}/Makefile"
