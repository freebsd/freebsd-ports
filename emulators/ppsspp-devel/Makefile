# $FreeBSD$

DISTVERSION=	1.7.5-533
DISTVERSIONSUFFIX=	-gbd71af24d
PORTREVISION?=	0
PKGNAMESUFFIX?=	-devel

GH_TUPLE=	hrydgard:glslang:9983f99e:glslang/ext/glslang \
		hrydgard:${PORTNAME}-lang:f97aa5d:lang/assets/lang \
		KhronosGroup:SPIRV-Cross:be7425e:SPIRV/ext/SPIRV-Cross \
		Kingcom:armips:v0.10.0-28-g7885552:armips/ext/armips \
		Kingcom:tinyformat:Release-2.0.1-7-gb7f5a22:tinyformat/ext/armips/ext/tinyformat

CMAKE_OFF=	USE_DISCORD

MASTERDIR=	${.CURDIR}/../ppsspp
DISTINFO_FILE?=	${.CURDIR}/distinfo

pre-patch:	slave-pre-patch
slave-pre-patch:
# Avoid copying entire ${PATCHDIR} just for removed code
	@${REINPLACE_CMD} -e '/SIMULATOR/s/ARM_DEVICE/ARM/' \
		${WRKSRC}/CMakeLists.txt

.include "${MASTERDIR}/Makefile"
