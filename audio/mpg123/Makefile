PORTNAME=	mpg123
DISTVERSION=	1.33.2
CATEGORIES=	audio
MASTER_SITES=	SF \
		https://www.mpg123.de/download/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Command-line player for MPEG Layer 1, 2, and 3 audio files
WWW=		https://www.mpg123.de/

LICENSE=	LGPL21

USES=		cpe tar:bzip2 libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-optimization=0
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		SNDIO
OPTIONS_DEFINE_i386=	OPTCPU
OPTIONS_DEFINE_armv6=	FPU
OPTIONS_DEFINE_armv7=	FPU
OPTIONS_DEFAULT_i386=	OPTCPU
OPTIONS_SUB=	yes

FPU_DESC=	Use fixed point arithmetic and/or NEON instructions
OPTCPU_DESC=	Enable support for optimized CPU instructions

TEST_TARGET=		check

FPU_CONFIGURE_ON=	--with-cpu=arm_fpu
FPU_CONFIGURE_OFF=	--with-cpu=arm_nofpu

SNDIO_CONFIGURE_ON=	--with-audio=sndio,oss
SNDIO_CONFIGURE_OFF=	--with-audio=oss
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_USES=		pkgconfig

OPTCPU_CONFIGURE_ON=	--with-cpu=x86
OPTCPU_CONFIGURE_OFF=	--with-cpu=generic_fpu

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--with-cpu=x86-64
.elif defined(MACHINE_CPU) && ${MACHINE_CPU:Maltivec}
CONFIGURE_ARGS+=	--with-cpu=altivec
.endif

.include <bsd.port.post.mk>
