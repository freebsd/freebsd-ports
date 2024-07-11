PORTNAME=	zphoto
PORTVERSION=	1.2
PORTREVISION=	16
CATEGORIES=	graphics www
MASTER_SITES=	http://namazu.org/~satoru/zphoto/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zooming photo album generator
WWW=		http://namazu.org/~satoru/zphoto/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on expired graphics/ming
EXPIRATION_DATE=2024-07-31

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libming.so:graphics/ming \
		libpopt.so:devel/popt

USES=		alias gmake localbase perl5 pkgconfig
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-avifile

OPTIONS_DEFINE=		NLS ZIP
OPTIONS_DEFAULT=	ZIP
OPTIONS_SUB=		yes

ZIP_DESC=	Enable zip support

NLS_USES=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

ZIP_RUN_DEPENDS=	zip:archivers/zip
ZIP_CONFIGURE_OFF=	--disable-zip

post-patch:
	@${REINPLACE_CMD} -e 's|<ming.h>|<ming/ming.h>|g' ${WRKSRC}/*.c ${WRKSRC}/configure

.include <bsd.port.mk>
