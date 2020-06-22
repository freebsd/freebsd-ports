# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lcms2
PORTVERSION=	2.11
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Accurate, fast, and small-footprint color management engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool localbase:ldflags pathfix

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	mm2
GH_PROJECT=	Little-CMS

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
	${INSTALL_DATA} ${WRKSRC}/doc/*.odt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
