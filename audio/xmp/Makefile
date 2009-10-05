# New ports collection makefile for: 	xmp
# Date created:				18 September 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xmp
PORTVERSION=	2.7.1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A player for many different Amiga and PC module formats

USE_GMAKE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-alsa --enable-oss \
		--sysconfdir=${PREFIX}/etc

MAN1=		xmp.1
MLINKS=		xmp.1 xxmp.1

OPTIONS=	XMMS	"Build XMMS plugin" off \
		ESOUND	"EsounD support" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=	--enable-xmms-plugin
PLIST_SUB+=		XMMS=""
.else
CONFIGURE_ARGS+=	--disable-xmms
PLIST_SUB+=		XMMS="@comment "
.endif

.include <bsd.port.post.mk>
