# Created by: Stefan Ehmann <shoesoft@gmx.net>
# $FreeBSD$

PORTNAME=	musepack
PORTVERSION=	2011.08.10
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/
DISTNAME=	${PORTNAME}_src_r475

MAINTAINER=	shoesoft@gmx.net
COMMENT=	Decoder, encoder, and replaygain for musepack (mpc)

LICENSE=	BSD3CLAUSE GPLv2 LGPL21 #or later for the (L)GPL'ed part
LICENSE_COMB=	multi

USES=		libtool
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal autoheader libtoolize automake autoconf
GNU_CONFIGURE=	yes
ACLOCAL_ARGS=	-I. -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing

.include <bsd.port.mk>
