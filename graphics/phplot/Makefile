# New ports collection makefile for:	phplot
# Date created:         21 Oct 2001
# Whom:                 yukinopo@livedoor.com
#
# $FreeBSD$

PORTNAME=	phplot
PORTVERSION=	5.1.2
CATEGORIES=	graphics www
MASTER_SITES=	SF:source1 \
		SF/${PORTNAME}/Manual/20100628:source2
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:source1 \
		${PORTNAME}docs-20100628.zip:source2

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A PHP class for creating scientific and business charts

LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd

USE_ZIP=	yes
USE_PHP=	yes
DEFAULT_PHP_VER=	5
IGNORE_WITH_PHP=	4
NO_BUILD=	YES

PHPLOT_DIR=	${PREFIX}/include/php/phplot

LIBS=		phplot.php phplot_data.php rgb.inc.php

OPTIONS=	FONTS "Install TrueType fonts" on

.if defined(WITH_FONTS)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
.endif

do-install:
	@${MKDIR} ${PHPLOT_DIR}
	@${INSTALL_DATA} ${LIBS:S,^,${WRKSRC}/,} ${PHPLOT_DIR}/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/phplotdocs && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif

.include <bsd.port.mk>
