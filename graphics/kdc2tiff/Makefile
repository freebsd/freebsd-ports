# Created by: will
# $FreeBSD$

PORTNAME=	kdc2tiff
PORTVERSION=	0.35
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts Kodak .kdc to TIFF or JPEG formats

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/kdc2jpeg bin/kdc2tiff

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|^main|int main|' ${WRKSRC}/kdc2tiff.cpp

.include <bsd.port.mk>
