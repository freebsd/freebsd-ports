# Created by: Carey Jones <mcj@acquiesce.org>
# $FreeBSD$

PORTNAME=	mpg123
PORTVERSION=	1.25.13
CATEGORIES=	audio
MASTER_SITES=	SF \
		http://www.mpg123.de/download/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Command-line player for MPEG Layer 1, 2, and 3 audio files

LICENSE=	LGPL21

USES=		tar:bzip2 gmake libtool localbase pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-optimization=0

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	SNDIO
OPTIONS_SUB=	yes

SNDIO_CONFIGURE_ON=	--with-audio=sndio,oss \
			--with-default-audio=sndio
SNDIO_CONFIGURE_OFF=	--with-audio=oss \
			--with-default-audio=oss
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
.if ${MACHINE_CPU:M3dnow}
WITH_CPU=	3dnow
.elif ${MACHINE_CPU:Msse}
WITH_CPU=	sse
.elif ${MACHINE_CPU:Mi586}
WITH_CPU=	i586
.elif ${MACHINE_CPU:Mi486}
WITH_CPU=	i486
.endif
.elif ${ARCH} == "amd64"
WITH_CPU=	x86-64
.elif ${ARCH} == "arm"
WITH_CPU=	arm_nofpu
.endif

.if defined(WITH_CPU)
CONFIGURE_ARGS+=	--with-cpu=${WITH_CPU}
.endif

.include <bsd.port.post.mk>
