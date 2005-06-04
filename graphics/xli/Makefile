# New ports collection makefile for:	xli
# Date created:		24 November 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	xli
PORTVERSION=	1.17.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://pantransit.reptiles.org/prog/xli/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications
DISTNAME=	xli-${XLI_SNAPVER}

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	Xli, xsetbg, xview, xlito - utilities to display images on X11

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/xli-${XLI_SNAPVER}

USE_XLIB=	yes
USE_IMAKE=	yes
USE_PERL5_BUILD=yes
MAN1=		xli.1 xlito.1

XLI_SNAPVER=	2005-02-27

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/Imakefile

.include <bsd.port.mk>
