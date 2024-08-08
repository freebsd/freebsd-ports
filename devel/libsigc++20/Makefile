PORTNAME=	libsigc++
DISTVERSION=	2.12.1
CATEGORIES=	devel
MASTER_SITES=	GNOME \
		https://github.com/libsigcplusplus/libsigcplusplus/releases/download/${DISTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++
WWW=		https://github.com/libsigcplusplus/libsigcplusplus

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^2\.12\.

USES=		compiler:c++11-lang meson tar:xz
USE_LDCONFIG=	yes

PLIST_SUB=	API_VERSION="2.0"

MESON_ARGS=	-Dbuild-documentation=false \
		-Dbuild-examples=false

.include <bsd.port.mk>
