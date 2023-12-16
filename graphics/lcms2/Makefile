PORTNAME=	lcms2
PORTVERSION=	2.16
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/mm2/Little-CMS/releases/download/lcms${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Accurate, fast, and small-footprint color management engine
WWW=		https://www.littlecms.com/ \
		https://github.com/mm2/Little-CMS

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe libtool localbase:ldflags pathfix

CONFIGURE_ARGS=	--with-fastfloat --with-threaded
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	littlecms
CPE_PRODUCT=	little_cms_color_engine

OPTIONS_DEFINE=	DOCS JPEGICC TIFFICC
OPTIONS_DEFAULT=JPEGICC TIFFICC
OPTIONS_SUB=	yes
JPEGICC_DESC=	Build color profile applier for JPEG
TIFFICC_DESC=	Build color profile applier for TIFF

JPEGICC_CONFIGURE_WITH=	jpeg
JPEGICC_USES=		jpeg
TIFFICC_CONFIGURE_WITH=	tiff
TIFFICC_LIB_DEPENDS=	libtiff.so:graphics/tiff

post-install:
	${INSTALL_MAN} ${WRKSRC}/utils/linkicc/linkicc.1 ${WRKSRC}/utils/psicc/psicc.1 ${WRKSRC}/utils/transicc/transicc.1 ${STAGEDIR}${PREFIX}/man/man1/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
