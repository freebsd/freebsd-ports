# New ports collection makefile for:	zphoto
# Date created:				19 Jul 2002
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	zphoto
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	graphics www
MASTER_SITES=	http://namazu.org/~satoru/zphoto/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Zooming photo album generator

LIB_DEPENDS=	ming.3:${PORTSDIR}/graphics/ming \
		Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		popt.0:${PORTSDIR}/devel/popt
.if !defined (WITHOUT_AVIPLAY)
LIB_DEPENDS+=	aviplay.0:${PORTSDIR}/multimedia/avifile
.endif
.if defined (WITH_WXGTK2)
LIB_DEPENDS+=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24
.endif
.if !defined (WITHOUT_ZIP)
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip
.endif

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
	       	CPPFLAGS="-I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}"
.if defined (WITH_WXGTK)
CONFIGURE_ARGS+=	--with-wx-config=wxgtk-2.4-config
PLIST+=		${PKGDIR}/pkg-plist.wxzphoto
.elif defined (WITH_WXGTK2)
CONFIGURE_ARGS+=	--with-wx-config=wxgtk2-2.4-config
.else
CONFIGURE_ARGS+=	--disable-wx
.endif
.if defined (WITHOUT_AVIPLAY)
CONFIGURE_ARGS+=	--disable-avifile
.endif
.if defined (WITHOUT_ZIP)
CONFIGURE_ARGS+=	--disable-zip
.endif
USE_GMAKE=	yes
USE_XLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<ming.h>|<ming/ming.h>|g' ${WRKSRC}/*.c ${WRKSRC}/configure

.include <bsd.port.mk>
