# Created by: UMENO Takashi <umeno@rr.iij4u.or.jp>
# $FreeBSD$

PORTNAME=	zphoto
PORTVERSION=	1.2
PORTREVISION=	14
CATEGORIES=	graphics www
MASTER_SITES=	http://namazu.org/~satoru/zphoto/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zooming photo album generator

OPTIONS_DEFINE=	ZIP
OPTIONS_DEFAULT=	ZIP
ZIP_DESC=	Enable zip support

LIB_DEPENDS=	libming.so:graphics/ming \
		libpopt.so:devel/popt \
		libImlib2.so:graphics/imlib2

ZIP_RUN_DEPENDS=	zip:archivers/zip
ZIP_CONFIGURE_OFF=	--disable-zip

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-avifile
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		alias gmake perl5
USE_PERL5=	build

post-patch:
	@${REINPLACE_CMD} -e 's|<ming.h>|<ming/ming.h>|g' ${WRKSRC}/*.c ${WRKSRC}/configure

.include <bsd.port.mk>
