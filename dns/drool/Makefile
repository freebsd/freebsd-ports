# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	drool
DISTVERSION=	1.0.1
CATEGORIES=	dns
MASTER_SITES=	https://www.dns-oarc.net/files/drool/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Replay DNS traffic from packet capture files

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libev.so:devel/libev

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	$$(pkg-config libev --cflags-only-I)
LDFLAGS+=	$$(pkg-config libev --libs-only-L)

.include <bsd.port.mk>
