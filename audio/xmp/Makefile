# New ports collection makefile for: 	xmp
# Date created:		18 September 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xmp
PORTVERSION=	2.5.1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
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

CFLAGS+=	-fPIC

.include <bsd.port.pre.mk>

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=	--enable-xmms-plugin
.else
CONFIGURE_ARGS+=	--disable-xmms
.endif

post-patch:
.for f in docs/xmp.1 etc/xmp.conf etc/xmp-modules.conf
	@${REINPLACE_CMD} -e "s|/etc/xmp|${PREFIX}/etc/xmp|g" ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -E -e 's|(^DDIRS.*)etc|\1|' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${PREFIX}/etc/xmp
	@${INSTALL_DATA} ${WRKSRC}/etc/xmp.conf ${PREFIX}/etc/xmp/xmp.conf.default
	@${INSTALL_DATA} ${WRKSRC}/etc/xmp-modules.conf ${PREFIX}/etc/xmp/xmp-modules.conf.default

.include <bsd.port.post.mk>
