# Created by: Michael Gmelin <freebsd@grem.de>
# $FreeBSD$

PORTNAME=		intel-backlight
PORTVERSION=		20150706
CATEGORIES=		graphics

MAINTAINER=		freebsd@grem.de
COMMENT=		Control backlight on various modern Intel(R) GPUs

LIB_DEPENDS=		libdrm.so:graphics/libdrm \
			libpciaccess.so:devel/libpciaccess

USE_GITHUB=		yes
GH_ACCOUNT=		grembo
GH_PROJECT=		intel_backlight_fbsd
GH_TAGNAME=		93e1fe4

PLIST_FILES=		bin/intel_backlight
PORTEXAMPLES=		isl_backlight.sh

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	This hardware is only found on Intel x86 systems

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -o intel_backlight -I${PREFIX}/include \
	-I${PREFIX}/include/libdrm  -L${PREFIX}/lib -ldrm_intel \
	-lpciaccess intel_reg_map.c intel_mmio.c intel_backlight.c \
	intel_drm.c intel_pci.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/intel_backlight ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/isl_backlight.sh ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
