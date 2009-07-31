# New ports collection makefile for:	libmcs
# Date created:				27th February 2007
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmcs
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.atheme.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A BSD licenced configuration database system

LIB_DEPENDS=	mowgli.2:${PORTSDIR}/devel/libmowgli

OPTIONS=	GCONF	"Enable gconf support"		on

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GCONF)
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=--enable-gconf
PLIST_SUB=	GCONF=""
.else
CONFIGURE_ARGS+=--disable-gconf
PLIST_SUB=	GCONF="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
