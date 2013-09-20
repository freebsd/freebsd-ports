# Created by: Tim Hemel
# $FreeBSD$

PORTNAME=	picviz
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	graphics security
MASTER_SITES=	http://www.wallinfire.net/picviz/attachment/wiki/ReleasesDownload/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}?format=raw

MAINTAINER=	ports@timit.nl
COMMENT=	Parallel coordinates plotter

LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre \
		cairo.2:${PORTSDIR}/graphics/cairo

USE_LDCONFIG=	yes
USES=		bison cmake

MAN1=		pcv.1

NO_STAGE=	yes
.include <bsd.port.mk>
