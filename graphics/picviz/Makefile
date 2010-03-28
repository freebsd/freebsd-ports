# New ports collection makefile for:	picviz
# Date created:         08 Nov 2008
# Whom:                 Tim Hemel
#
# $FreeBSD$
#

PORTNAME=	picviz
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	graphics security
MASTER_SITES=	http://www.wallinfire.net/picviz/attachment/wiki/ReleasesDownload/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}?format=raw

MAINTAINER=	ports@timit.nl
COMMENT=	Parallel coordinates plotter

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		cairo.2:${PORTSDIR}/graphics/cairo

USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_BISON=	build

MAN1=		pcv.1

.include <bsd.port.mk>
