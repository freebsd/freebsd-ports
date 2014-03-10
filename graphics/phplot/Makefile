# Created by: yukinopo@livedoor.com
# $FreeBSD$

PORTNAME=	phplot
PORTVERSION=	6.1.0
PORTREVISION=	1
CATEGORIES=	graphics www
MASTER_SITES=	SF:source1 \
		SF/${PORTNAME}/Manual/20130511:source2
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:source1 \
		${PORTNAME}docs-20130511.zip:source2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP class for creating scientific and business charts

LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd

USES=		zip
USE_PHP=	yes
DEFAULT_PHP_VER=	5
NO_BUILD=	YES

PHPLOT_DIR=	${PREFIX}/include/php/phplot

LIBS=		phplot.php rgb.inc.php

OPTIONS_DEFINE=		FONTS
OPTIONS_DEFAULT=	FONTS
FONTS_DESC=		install TrueType fonts

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFONTS}
LIB_DEPENDS+=	freetype:${PORTSDIR}/print/freetype2
.endif

do-install:
	@${MKDIR} ${PHPLOT_DIR}
	@${INSTALL_DATA} ${LIBS:S,^,${WRKSRC}/,} ${PHPLOT_DIR}/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/phplotdocs && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif

.include <bsd.port.mk>
