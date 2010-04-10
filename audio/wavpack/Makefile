# New ports collection makefile for:	wavpack
# Date created:			Fri Jun 24 20:30:04 CEST 2005
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wavpack
PORTVERSION=	4.60.1
CATEGORIES=	audio
MASTER_SITES=	http://www.wavpack.com/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Audio codec for lossless, lossy and hybrid compression

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_ICONV=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

OPTIONS=	MMX "Enable MMX optimizations (x86 only)" Off

MAN1=	wavpack.1 wvgain.1 wvunpack.1

.include <bsd.port.pre.mk>

# GCC 3.x fails with internal compiler errror
.if defined(WITH_MMX) && (${ARCH} == "i386" || ${ARCH} == "amd64") && \
    (${OSVERSION} >= 700042)
CONFIGURE_ARGS+=	--enable-mmx
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

.include <bsd.port.post.mk>
