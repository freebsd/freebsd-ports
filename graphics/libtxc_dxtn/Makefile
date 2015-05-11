# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtxn_dxtn
PORTVERSION=	20140604
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Subset of a well-known texture compression scheme

LICENSE=	MIT

BUILD_DEPENDS=	libGL>=9.1.7:${PORTSDIR}/graphics/libGL

USE_GITHUB=	yes
GH_ACCOUNT=	divVerent
GH_PROJECT=	s2tc
GH_TAGNAME=	3d644da

USES=		autoreconf libtool pathfix pkgconfig
PATHFIX_MAKEFILEIN=Makefile.am
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--disable-tools

CPPFLAGS+=	-I${LOCALBASE}/include

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
