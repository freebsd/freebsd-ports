# New ports collection makefile for:	cairomm
# Date created:		2005-12-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cairomm
PORTVERSION=	0.6.0
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo

LIB_DEPENDS=	xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26 \
		cairo.2:${PORTSDIR}/graphics/cairo

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN="Does not build"
.endif

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-docs

post-patch:
	@${REINPLACE_CMD} -E '/^SUBDIRS = /s/(docs|examples)//g' ${WRKSRC}/Makefile.in
.else
post-configure:
	@${TOUCH} -f ${WRKSRC}/docs/reference/html/index.html
.endif

.include <bsd.port.post.mk>
