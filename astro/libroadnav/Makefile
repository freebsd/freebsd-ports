# Created by: Steve Franks <stevefranks@ieee.org>
# $FreeBSD$

PORTNAME=	libroadnav
PORTVERSION=	0.19
PORTREVISION=	5
CATEGORIES=	astro geography
MASTER_SITES=	SF/roadnav/LibRoadnav/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helper library for Roadnav (3D GPS mapping program)

OPTIONS_DEFINE=	DOCS

USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_UNICODE=	yes
USES=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-prefix=${LOCALBASE} --with-wx-config=${WX_CONFIG}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

.include <bsd.port.mk>
