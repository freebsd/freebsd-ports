PORTNAME=	jrtplib
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.2
CATEGORIES=	devel

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Object-oriented RTP library written in C++
WWW=		https://research.edm.uhasselt.be/jori/page/Cs/JrtplibOld.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.MIT

DEPRECATED=	Abandonware, no longer maintained upstream as of 2020
EXPIRATION_DATE=2025-03-31

LIB_DEPENDS=	libsrtp2.so:net/libsrtp2

USES=		cmake pathfix tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	j0r1
GH_PROJECT=	JRTPLIB
USE_LDCONFIG=	yes

PLIST_SUB=	JRTPLIB_VER="${DISTVERSION:C/-.*//}"

.include <bsd.port.mk>
