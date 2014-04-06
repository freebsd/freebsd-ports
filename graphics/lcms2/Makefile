# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lcms2
PORTVERSION=	2.6
CATEGORIES=	graphics
MASTER_SITES=	SF/lcms/lcms/${PORTVERSION} \
		http://www.littlecms.com/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Accurate, fast, and small-footprint color management engine

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS JPEGICC TIFFICC
OPTIONS_DEFAULT=JPEGICC TIFFICC
OPTIONS_SUB=	yes
JPEGICC_DESC=	Build color profile applier for JPEG
TIFFICC_DESC=	Build color profile applier for TIFF

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		libtool pathfix

PORTDOCS=	*

JPEGICC_CONFIGURE_OFF=	--without-jpeg
JPEGICC_CONFIGURE_ON=	--with-jpeg=${LOCALBASE}
JPEGICC_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
TIFFICC_CONFIGURE_OFF=	--without-tiff
TIFFICC_CONFIGURE_ON=	--with-tiff=${LOCALBASE}
TIFFICC_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff

post-install:
	cd ${WRKSRC}/utils/ && ${INSTALL_MAN} linkicc/linkicc.1 psicc/psicc.1 transicc/transicc.1 ${STAGEDIR}${PREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblcms2.so.2.0.6

regression-test test: build
	cd ${WRKSRC}/testbed/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
