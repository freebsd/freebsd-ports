# Created by: Steve Franks <stevefranks@ieee.org>
# $FreeBSD$

PORTNAME=	roadnav
PORTVERSION=	0.19
PORTREVISION=	7
CATEGORIES=	astro geography
MASTER_SITES=	SF/${PORTNAME}/Roadnav/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D GPS mapping program

DEPRECATED=	No releases for 8+ years, no supporting newer wxWidget
EXPIRATION_DATE=	2015-12-13

BUILD_DEPENDS=	${LOCALBASE}/lib/libroadnav.a:${PORTSDIR}/astro/libroadnav

USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_UNICODE=	yes
USES=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-prefix=${LOCALBASE} --with-wx-config=${WX_CONFIG}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
