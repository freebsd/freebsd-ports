# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vtg
PORTVERSION=	0.12.0
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
# Fow now, only devel/monodevelop depend on vtg but the bindings have changed,
# so use the old beta release before a new monodevelop version is available.
# Since the 0.12 serie is for gEdit 3+, it should not be a big problem for now.
DISTNAME=	${PORTNAME}-${PORTVERSION}_beta5

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Vala Toys for gEdit

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
RUN_DEPENDS=	valac:${PORTSDIR}/lang/vala

IGNORE=		doesn't build with vala 0.18+

CONFIGURE_ARGS=	--disable-vtg-plugin --disable-gen-project
CPPFLAGS=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USES=		gmake tar:bzip2
USE_GNOME=	gnomehack glib20 intltool
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
