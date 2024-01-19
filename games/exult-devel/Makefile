DISTVERSIONPREFIX=	snapshot-v
DISTVERSION=	1.9.0.20240105
PORTREVISION=	0 # Always set PORTREVISION explicitly as otherwise it is inherited from games/exult
PKGNAMESUFFIX=	-devel

CONFLICTS_INSTALL=	exult

STUDIO_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz \
			libicuuc.so:devel/icu

MASTERDIR=	${.CURDIR}/../exult
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
