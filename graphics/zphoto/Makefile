# Created by: UMENO Takashi <umeno@rr.iij4u.or.jp>
# $FreeBSD$

PORTNAME=	zphoto
PORTVERSION=	1.2
PORTREVISION=	12
CATEGORIES=	graphics www
MASTER_SITES=	http://namazu.org/~satoru/zphoto/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Zooming photo album generator

OPTIONS_DEFINE=	ZIP
OPTIONS_DEFAULT=	ZIP
ZIP_DESC=	Enable zip support

LIB_DEPENDS=	libming.so:${PORTSDIR}/graphics/ming \
		libpopt.so:${PORTSDIR}/devel/popt

ZIP_RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip
ZIP_CONFIGURE_OFF=	--disable-zip

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-avifile
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}
USE_EFL=	imlib2
PLIST_FILES+=	bin/wxzphoto
USES=		perl5 gmake
USE_PERL5=	build

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|<ming.h>|<ming/ming.h>|g' ${WRKSRC}/*.c ${WRKSRC}/configure

.include <bsd.port.mk>
