# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lcms2
PORTVERSION=	2.7
CATEGORIES=	graphics
MASTER_SITES=	SF/lcms/lcms/${PORTVERSION}

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
INSTALL_TARGET=	install-strip
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		libtool:keepla pathfix

PORTDOCS=	*

JPEGICC_CONFIGURE_OFF=	--without-jpeg
JPEGICC_CONFIGURE_ON=	--with-jpeg=${LOCALBASE}
JPEGICC_USES=		jpeg
TIFFICC_CONFIGURE_OFF=	--without-tiff
TIFFICC_CONFIGURE_ON=	--with-tiff=${LOCALBASE}
TIFFICC_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff

post-install:
	cd ${WRKSRC}/utils/ && ${INSTALL_MAN} linkicc/linkicc.1 psicc/psicc.1 transicc/transicc.1 ${STAGEDIR}${PREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}/

regression-test test: build
	cd ${WRKSRC}/testbed/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
