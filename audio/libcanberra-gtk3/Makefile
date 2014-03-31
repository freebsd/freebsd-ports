# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/libcanberra-gtk3/Makefile,v 1.8 2011/03/16 10:24:48 kwm Exp $

PORTREVISION=	1
CATEGORIES=	audio devel
PKGNAMESUFFIX=	-gtk3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec

MASTERDIR=	${.CURDIR}/../../audio/libcanberra
SLAVEPORT=	gtk3
PLIST=		${.CURDIR}/pkg-plist

do-build:
	cd ${WRKSRC} && ${GMAKE} libcanberra-gtk3.pc
	cd ${WRKSRC}/src && ${GMAKE} libcanberra-gtk3.la
	cd ${WRKSRC}/src && ${GMAKE} libcanberra-gtk3-module.la
# fix the .la file so it doesn't point to the build dir anymore.
	@${REINPLACE_CMD} -e '/^relink_command/ d' \
		-e 's|${WRKSRC}/src/libcanberra.la|${LOCALBASE}/lib/libcanberra.la|g' \
		${WRKSRC}/src/.libs/libcanberra-gtk3.la

do-install:
	${INSTALL_DATA} ${WRKSRC}/libcanberra-gtk3.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/
.for i in .a .la .so .so.0
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libcanberra-gtk3${i} \
		${STAGEDIR}${PREFIX}/lib/
.endfor
	cd ${WRKSRC}/src && ${SETENV} DESTDIR=${STAGEDIR} \
		${GMAKE} install-gtk3moduleLTLIBRARIES
	cd ${STAGEDIR}${PREFIX}/lib/gtk-3.0/modules && \
		${LN} -sf libcanberra-gtk3-module.so libcanberra-gtk-module.so

.include "${MASTERDIR}/Makefile"
