# Created by: Steve Franks <stevefranks@ieee.org>
# $FreeBSD$

PORTNAME=	roadnav
PORTVERSION=	0.19
PORTREVISION=	4
CATEGORIES=	astro geography
MASTER_SITES=	SF/${PORTNAME}/Roadnav/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D GPS mapping program

BUILD_DEPENDS=	${LOCALBASE}/lib/libroadnav.a:${PORTSDIR}/astro/libroadnav

USE_WX=		2.6+
WX_COMPS=	wx contrib
USES=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-prefix=${LOCALBASE} --with-wx-config=${WX_CONFIG}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

.include <bsd.port.pre.mk>

pre-su-install:
	@${MKDIR} ${PREFIX}/share/applications

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/src/Makefile.in
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^install-data-am:/s|install-roadnavdocDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
