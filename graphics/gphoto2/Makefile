PORTNAME=	gphoto2
PORTVERSION=	2.5.28
CATEGORIES=	graphics
MASTER_SITES=	SF/gphoto/gphoto/${PORTVERSION} \
		https://github.com/gphoto/gphoto2/releases/download/v${PORTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Command-line frontend to libgphoto2
WWW=		http://www.gphoto.org/proj/gphoto2/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libgphoto2.so:graphics/libgphoto2 \
		libpopt.so:devel/popt
TEST_DEPENDS=	gsed:textproc/gsed

USES=		jpeg pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-cdk
TEST_TARGET=	check

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=		AALIB DOCS NLS READLINE THREADS
OPTIONS_DEFAULT=	AALIB READLINE THREADS
OPTIONS_SUB=		yes

AALIB_DESC=		Text mode capture preview support
AALIB_LIB_DEPENDS=	libaa.so:graphics/aalib
AALIB_CONFIGURE_ON=	--with-aalib

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

READLINE_USES=		readline
READLINE_CONFIGURE_OFF=	--without-readline

THREADS_CONFIGURE_OFF=	--without-pthread

post-patch:
	@${REINPLACE_CMD} -e '1s,bash,sh,; /SEDCOMMAND/s,sed,g&,' \
		${WRKSRC}/tests/testsuite

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
