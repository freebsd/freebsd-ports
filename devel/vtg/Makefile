# New ports collection makefile for:	vtg
# Date created:		2011-10-09
# Whom:			Romain Tartiere <romain@FreeBSD.org>
#
# $FreeBSD$
#

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

CONFIGURE_ARGS=	--disable-vtg-plugin --disable-gen-project
CPPFLAGS=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 intltool
USE_LDCONFIG=	yes

.include <bsd.port.mk>
