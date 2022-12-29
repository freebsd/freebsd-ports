DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0.20221213
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

CONFLICTS_INSTALL=	exult

LIB_DEPENDS=	libogg.so:audio/libogg \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis
STUDIO_LIB_DEPENDS=	libfreetype.so:print/freetype2

MASTERDIR=	${.CURDIR}/../exult
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
