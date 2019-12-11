# $FreeBSD$

PORTNAME=	string-machine
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Digital model of electronic string ensemble instrument

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/boost/intrusive/list.hpp:devel/boost-libs

USES=		compiler:c++0x gmake gnome localbase pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	jpcima
GH_TUPLE=	DISTRHO:DPF:7a056bb:d/dpf
USE_GNOME=	cairo
USE_XORG=	x11

CFLAGS+=	-I${FILESDIR} -pthread

SIMD_CFLAGS_i386=	"-msse -mfpmath=sse"
SIMD_CFLAGS_amd64=	"-msse2 -mfpmath=sse"
SIMD_CFLAGS_armv7=	"-march=armv7 -mfpu=vfpv3"

MAKE_ARGS=	SIMD_CFLAGS=${SIMD_CFLAGS_${ARCH}}

PLIST_FILES=	lib/lv2/string-machine.lv2/manifest.ttl \
		lib/lv2/string-machine.lv2/presets.ttl \
		lib/lv2/string-machine.lv2/string-machine.so \
		lib/lv2/string-machine.lv2/string-machine.ttl \
		lib/vst/string-machine-vst.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/lv2/${PORTNAME}.lv2
	${INSTALL_LIB} ${WRKSRC}/bin/${PORTNAME}.lv2/string-machine.so ${STAGEDIR}${PREFIX}/lib/lv2/${PORTNAME}.lv2
.for f in manifest.ttl presets.ttl string-machine.ttl
	${INSTALL_DATA} ${WRKSRC}/bin/${PORTNAME}.lv2/${f} ${STAGEDIR}${PREFIX}/lib/lv2/${PORTNAME}.lv2
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst
	${INSTALL_LIB} ${WRKSRC}/bin/string-machine-vst.so ${STAGEDIR}${PREFIX}/lib/vst

.include <bsd.port.mk>
