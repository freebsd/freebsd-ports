# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	tomboy-plugin-latex
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.reitwiessner.de/programs/tomboy-latex/v${PORTVERSION}/
DISTNAME=	tomboy-latex-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	LaTeX math plugin for Tomboy

BROKEN=		unfetchable

BUILD_DEPENDS=	tomboy:deskutils/tomboy
RUN_DEPENDS=	tomboy:deskutils/tomboy

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GMCS=${LOCALBASE}/bin/mcs
MAKE_ARGS=	CSC="${LOCALBASE}/bin/mcs -debug"
USES=		gmake pkgconfig
USE_TEX=	latex

.include <bsd.port.mk>
