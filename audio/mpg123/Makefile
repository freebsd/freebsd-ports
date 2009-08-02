# New ports collection makefile for:	mpg123
# Date created:			25 June 1997
# Whom:				Carey Jones <mcj@acquiesce.org>
#
# $FreeBSD$
#

PORTNAME=	mpg123
PORTVERSION=	1.6.4
PORTREVISION=	1
CATEGORIES=	audio ipv6
MASTER_SITES=	SF \
		http://www.mpg123.de/download/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio

USE_BZIP2=	yes
USE_AUTOTOOLS=	libltdl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-audio=oss \
		--with-default-audio=oss
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CONFIG_SHELL=${SH} CFLAGS="${CFLAGS} -I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		mpg123.1

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
.endif

.if defined(WITH_CPU)
CONFIGURE_ARGS+=--with-cpu=${WITH_CPU}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
