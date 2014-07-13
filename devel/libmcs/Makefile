# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmcs
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.atheme.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	BSD licenced configuration database system

LIB_DEPENDS=	libmowgli.so:${PORTSDIR}/devel/libmowgli

OPTIONS_DEFINE=	GCONF
OPTIONS_DEFAULT=	GCONF

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCONF}
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

.include <bsd.port.mk>
