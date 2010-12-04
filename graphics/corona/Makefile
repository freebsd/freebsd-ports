# New ports collection makefile for:	corona
# Date created:				25 May 2004
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$

PORTNAME=	corona
PORTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphics library that supports most image formats

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_AUTOTOOLS=	libtool
USE_GNOME=	gnometarget lthack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LIBS} -L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e \
		's|-Wall||' \
		${WRKSRC}/configure

.include <bsd.port.mk>
