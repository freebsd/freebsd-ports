# Created by: Carey Jones <mcj@acquiesce.org>
# $FreeBSD$

PORTNAME=	mpg123
PORTVERSION=	1.26.3
CATEGORIES=	audio
MASTER_SITES=	SF \
		https://www.mpg123.de/download/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Command-line player for MPEG Layer 1, 2, and 3 audio files

LICENSE=	LGPL21

USES=		tar:bzip2 libtool localbase pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
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

SNDIO_CONFIGURE_ON=	--with-audio=sndio,oss \
			--with-default-audio=sndio
SNDIO_CONFIGURE_OFF=	--with-audio=oss \
			--with-default-audio=oss
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio

OPTCPU_CONFIGURE_ON=	--with-cpu=x86
OPTCPU_CONFIGURE_OFF=	--with-cpu=generic_fpu

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--with-cpu=x86-64
.endif

.include <bsd.port.post.mk>
