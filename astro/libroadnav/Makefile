# ex:ts=8
# Ports collection makefile for:	roadnav
# Date created:				28 July 2008
# Whom:					stevef
#
# $FreeBSD$
#

PORTNAME=	libroadnav
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	SF/roadnav/LibRoadnav/${PORTVERSION}

MAINTAINER=	bahamasfranks@gmail.com
COMMENT=	Helper library for Roadnav: A 3D GPS Mapping program

USE_WX=		2.6+
WX_COMPS=	wx contrib
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-prefix=${LOCALBASE} --with-wx-config=${WX_CONFIG}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	*

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-libroadnavdocDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
