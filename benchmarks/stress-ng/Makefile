PORTNAME=	stress-ng
DISTVERSIONPREFIX=	V
DISTVERSION=	0.19.02
PORTREVISION=	0
CATEGORIES=	benchmarks

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Stress test benchmarks
WWW=		https://github.com/ColinIanKing/stress-ng

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=libmpfr.so:math/mpfr

USES=		compiler:c11 gmake jpeg localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	ColinIanKing

ALL_TARGET=	# empty

PLIST_FILES=	bin/stress-ng share/man/man1/stress-ng.1.gz

OPTIONS_DEFINE=		GPU JUDY LIBINOTIFY XXHASH
OPTIONS_DEFINE_amd64=	INTELIPSEC
OPTIONS_DEFAULT=	JUDY LIBINOTIFY XXHASH
OPTIONS_DEFAULT_amd64=	INTELIPSEC

GPU_DESC=	Enable support for GPU stressor (add GL)
INTELIPSEC_DESC=	Enable support for Intel's IPsec library
JUDY_DESC=		Enable support for (lib)Judy
LIBINOTIFY_DESC=	Enable support for libinotify
XXHASH_DESC=	Enable support for libxxhash

INTELIPSEC_LIB_DEPENDS=		libIPSec_MB.so:security/intel-ipsec-mb

JUDY_LIB_DEPENDS=		libJudy.so:devel/judy

LIBINOTIFY_LIB_DEPENDS=		libinotify.so:devel/libinotify
LIBINOTIFY_LDFLAGS=		-linotify

XXHASH_LIB_DEPENDS=	libxxhash.so:devel/xxhash
XXHASH_LDFLAGS=	-lxxhash

GPU_USES=	gl

CFLAGS_powerpc=	-O0
MAKE_ARGS=	VERBOSE=1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPU}
USE_GL=	egl glesv2 gbm
.endif

pre-patch:
	${MKDIR} ${WRKSRC}/configs
	${TOUCH} ${WRKSRC}/configs/HAVE_CRYPT_H
.if ${ARCH} == i386
	${TOUCH} ${WRKSRC}/configs/HAVE_VECMATH
.endif

#to dsiable Intel IPSEC detection
post-patch-INTELIPSEC-off:
	${TOUCH} ${WRKSRC}/configs/HAVE_LIB_IPSEC_MB
	${TOUCH} ${WRKSRC}/configs/HAVE_INTEL_IPSEC_MB_H

#to dsiable judy detection
post-patch-JUDY-off:
	${TOUCH} ${WRKSRC}/configs/HAVE_JUDY_H
	${TOUCH} ${WRKSRC}/configs/HAVE_LIB_JUDY

#to dsiable libinotify detection
post-patch-LIBINOTIFY-off:
	${TOUCH} ${WRKSRC}/configs/HAVE_INOTIFY
	${TOUCH} ${WRKSRC}/configs/HAVE_SYS_INOTIFY

# To disable libxxhash
post-patch-XXHASH-off:
	${TOUCH} ${WRKSRC}/configs/HAVE_LIB_XXHASH
	${TOUCH} ${WRKSRC}/configs/HAVE_XXHASH_H

post-patch-GPU-off:
	${TOUCH} ${WRKSRC}/configs/HAVE_LIB_EGL
	${TOUCH} ${WRKSRC}/configs/HAVE_EGL_H
	${TOUCH} ${WRKSRC}/configs/HAVE_EGL_EXT_H
	${TOUCH} ${WRKSRC}/configs/HAVE_LIB_GLES2
	${TOUCH} ${WRKSRC}/configs/HAVE_GLES2_H
	${TOUCH} ${WRKSRC}/configs/HAVE_LIB_GBM
	${TOUCH} ${WRKSRC}/configs/HAVE_GBM_H

do-configure:
	cd ${WRKSRC} && ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} ${_MAKE_JOBS} config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stress-ng ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/stress-ng.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
