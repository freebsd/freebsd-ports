# New ports collection makefile for:	musepack
# Date created:				2004-04-16
# Whom:					Stefan Ehmann <shoesoft@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	musepack
PORTVERSION=	2009.03.01
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/
DISTNAME=	${PORTNAME}_src_r435

MAINTAINER=	shoesoft@gmx.net
COMMENT=	Decoder, encoder and replaygain for musepack (mpc)

CONFLICTS=	libmpcdec-[0-9]*

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:110 autoheader:262 libtoolize automake:110 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I. -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build on 6.X
.endif

.include <bsd.port.post.mk>
