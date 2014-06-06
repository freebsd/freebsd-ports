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

BUILD_DEPENDS=	tomboy:${PORTSDIR}/deskutils/tomboy
RUN_DEPENDS=	tomboy:${PORTSDIR}/deskutils/tomboy

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_TEX=	latex

.include <bsd.port.mk>
