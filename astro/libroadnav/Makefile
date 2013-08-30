# Created by: Steve Franks <stevefranks@ieee.org>
# $FreeBSD$

PORTNAME=	libroadnav
PORTVERSION=	0.19
PORTREVISION=	4
CATEGORIES=	astro geography
MASTER_SITES=	SF/roadnav/LibRoadnav/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helper library for Roadnav (3D GPS mapping program)

USE_WX=		2.6+
WX_COMPS=	wx contrib
USES=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-prefix=${LOCALBASE} --with-wx-config=${WX_CONFIG}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

.include <bsd.port.pre.mk>

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e \
		'/^install-data-am:/s|install-libroadnavdocDATA||' \
			${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
