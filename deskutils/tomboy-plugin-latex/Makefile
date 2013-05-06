# New ports collection makefile for:	tomboy-plugin-latex
# Date created:		2008-12-21
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	tomboy-plugin-latex
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.reitwiessner.de/programs/tomboy-latex/v${PORTVERSION}/
DISTNAME=	tomboy-latex-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	LaTeX math plugin for Tomboy

BUILD_DEPENDS=	tomboy:${PORTSDIR}/deskutils/tomboy
RUN_DEPENDS=	tomboy:${PORTSDIR}/deskutils/tomboy

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_TEX=	tetex

.include <bsd.port.mk>
