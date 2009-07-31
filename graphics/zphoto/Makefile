# New ports collection makefile for:	zphoto
# Date created:				19 Jul 2002
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	zphoto
PORTVERSION=	1.2
PORTREVISION=	7
CATEGORIES=	graphics www
MASTER_SITES=	http://namazu.org/~satoru/zphoto/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Zooming photo album generator

LIB_DEPENDS=	ming.4:${PORTSDIR}/graphics/ming \
		popt.0:${PORTSDIR}/devel/popt
.if !defined (WITHOUT_AVIPLAY)
LIB_DEPENDS+=	aviplay.0:${PORTSDIR}/multimedia/avifile
.endif
.if !defined (WITHOUT_ZIP)
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
	       	CPPFLAGS="-I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}"
USE_EFL=	imlib2
.if defined (WITH_WXGTK2)
USE_WX=		2.4
WX_CONF_ARGS=	absolute
PLIST_FILES+=	bin/wxzphoto
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
USE_PERL5_BUILD=yes

post-patch:
	@${REINPLACE_CMD} -e 's|<ming.h>|<ming/ming.h>|g' ${WRKSRC}/*.c ${WRKSRC}/configure

.include <bsd.port.mk>
