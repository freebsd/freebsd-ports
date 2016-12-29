# Created by: UMENO Takashi <umeno@rr.iij4u.or.jp>
# $FreeBSD$

PORTNAME=	zphoto
PORTVERSION=	1.2
PORTREVISION=	14
CATEGORIES=	graphics www
MASTER_SITES=	http://namazu.org/~satoru/zphoto/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zooming photo album generator

LIB_DEPENDS=	libming.so:graphics/ming \
		libpopt.so:devel/popt \
		libImlib2.so:graphics/imlib2

USES=		alias gmake localbase perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-avifile

OPTIONS_DEFINE=		ZIP NLS
OPTIONS_DEFAULT=	ZIP
OPTIONS_SUB=		yes

ZIP_DESC=		Enable zip support
ZIP_RUN_DEPENDS=	zip:archivers/zip
ZIP_CONFIGURE_OFF=	--disable-zip

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|<ming.h>|<ming/ming.h>|g' ${WRKSRC}/*.c ${WRKSRC}/configure

.include <bsd.port.mk>
