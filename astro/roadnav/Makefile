# ex:ts=8
# Ports collection makefile for:	roadnav
# Date created:				28 July 2008
# Whom:					stevef
#
# $FreeBSD$
#

PORTNAME=	roadnav
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	SF/${PORTNAME}/Roadnav/${PORTVERSION}

MAINTAINER=	bahamasfranks@gmail.com
COMMENT=	A 3D GPS Mapping program

BUILD_DEPENDS=	${LOCALBASE}/lib/libroadnav.a:${PORTSDIR}/astro/libroadnav

USE_WX=		2.6+
WX_COMPS=	wx contrib
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-prefix=${LOCALBASE} --with-wx-config=${WX_CONFIG}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	*

pre-install:
	${MKDIR} ${PREFIX}/share/applications

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/src/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-roadnavdocDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
