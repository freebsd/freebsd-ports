# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmowgli
PORTVERSION=	1.0.0
CATEGORIES=	devel

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Development framework for C

LICENSE=	ISCL

USE_GITHUB=	yes
GH_ACCOUNT=	atheme-legacy
GH_TAGNAME=	5ab559e3af5b11767ada53d4401fb1c4443f3723

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} 's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
