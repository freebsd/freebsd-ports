# New ports collection makefile for: 	xmp
# Date created:		18 September 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xmp
PORTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A player for many different Amiga and PC module formats

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" CFLAGS="-I${LOCALBASE}/include -fPIC"
USE_AUTOCONF=	yes
WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500013 || ${MACHINE_ARCH} == "alpha"
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--disable-oss --enable-esd
PKGNAMESUFFIX=	-esound
.elif ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--enable-esd
PKGNAMESUFFIX=	-esound
.endif

.if !defined(WITHOUT_XMMS)
  LIB_DEPENDS+=   xmms.4:${PORTSDIR}/multimedia/xmms
.else
  CONFIGURE_ARGS+= --disable-xmms
.endif

MAN1=		xmp.1
MLINKS=		xmp.1 xxmp.1

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/docs/xmp.1

.include <bsd.port.post.mk>
