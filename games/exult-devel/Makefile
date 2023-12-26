DISTVERSIONPREFIX=	snapshot-v
DISTVERSION=	1.9.0.20231225
PORTREVISION=	0 # Do not remove PORTREVISION or it will be set to master
PKGNAMESUFFIX=	-devel

CONFLICTS_INSTALL=	exult

STUDIO_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
			libicuuc.so:devel/icu

MASTERDIR=	${.CURDIR}/../exult
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
