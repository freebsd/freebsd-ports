# New ports collection makefile for:	zphoto
# Date created:				19 Jul 2002
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	zphoto
PORTVERSION=	1.0
CATEGORIES=	graphics www
MASTER_SITES=	http://namazu.org/~satoru/zphoto/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Zooming photo album generator

LIB_DEPENDS=	ming.3:${PORTSDIR}/graphics/ming \
		Imlib2.2:${PORTSDIR}/graphics/imlib2 \
		popt.0:${PORTSDIR}/devel/popt \
		aviplay.0:${PORTSDIR}/multimedia/avifile
.if defined (WITH_WXGTK)
LIB_DEPENDS+=	wx_gtk-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk
.elif defined (WITH_WXGTK2)
LIB_DEPENDS+=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2
.endif
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
	       	CPPFLAGS="-I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}"
.if defined (WITH_WXGTK) || (WITH_WXGTK2)
PLIST+=		${PKGDIR}/pkg-plist.wxzphoto
.else
CONFIGURE_ARGS=	--disable-wx
.endif
USE_GMAKE=	yes
USE_XLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<ming.h>|<ming/ming.h>|g' ${WRKSRC}/*.c ${WRKSRC}/configure
.if defined (WITH_WXGTK)
	@${REINPLACE_CMD} -e 's|wxgtk2-config||g' -e 's|wxgtk2-2.5-config||g' -e 's|wxgtk2-2.4-config||g' ${WRKSRC}/configure
.elif defined (WITH_WXGTK2)
	@${REINPLACE_CMD} -e 's|wx-config||g' -e 's|wxgtk-config||g' ${WRKSRC}/configure
.endif
.include <bsd.port.mk>
