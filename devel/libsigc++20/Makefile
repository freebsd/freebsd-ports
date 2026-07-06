PORTNAME=	libsigc++
DISTVERSION=	2.12.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libsigcplusplus/libsigcplusplus/releases/download/${DISTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++
WWW=		https://github.com/libsigcplusplus/libsigcplusplus

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^2\.12\.

USES=		compiler:c++11-lang meson tar:xz
USE_LDCONFIG=	yes

MESON_ARGS=	-Dbuild-documentation=false \
		-Dbuild-examples=false

PLIST_SUB=	API_VERSION="2.0"

.include <bsd.port.mk>
