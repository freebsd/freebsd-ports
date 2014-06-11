# Created by: yukinopo@livedoor.com
# $FreeBSD$

PORTNAME=	phplot
PORTVERSION=	6.1.0
PORTREVISION=	2
CATEGORIES=	graphics www
MASTER_SITES=	SF:source1 \
		SF/${PORTNAME}/Manual/20130511:source2
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:source1 \
		${PORTNAME}docs-20130511.zip:source2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP class for creating scientific and business charts

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

USES=		zip
USE_PHP=	yes
DEFAULT_PHP_VER=	5
NO_BUILD=	YES

PHPLOT_DIR=	${STAGEDIR}${PREFIX}/include/php/phplot

LIBRARIES=	phplot.php rgb.inc.php

OPTIONS_DEFINE=		DOCS FONTS
OPTIONS_DEFAULT=	FONTS
FONTS_DESC=		install TrueType fonts
FONTS_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

do-install:
	@${MKDIR} ${PHPLOT_DIR}
	${INSTALL_DATA} ${LIBRARIES:S,^,${WRKSRC}/,} ${PHPLOT_DIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/phplotdocs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
