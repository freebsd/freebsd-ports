# Created by: Stefan Ehmann <shoesoft@gmx.net>
# $FreeBSD$

PORTNAME=	musepack
PORTVERSION=	2009.03.01
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/
DISTNAME=	${PORTNAME}_src_r435

MAINTAINER=	shoesoft@gmx.net
COMMENT=	Decoder, encoder, and replaygain for musepack (mpc)

USE_LDCONFIG=	yes
NO_STAGE=	yes
USE_AUTOTOOLS=	aclocal autoheader libtoolize automake autoconf libtool
ACLOCAL_ARGS=	-I. -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing

.include <bsd.port.mk>
