PORTNAME=	libsigc++
PORTVERSION=	2.12.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++
WWW=		http://libsigc.sourceforge.net/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^2\.12\.

INSTALL_TARGET=	install-strip
USES=		compiler:c++11-lang meson tar:xz
USE_LDCONFIG=	yes

PLIST_SUB=	API_VERSION="2.0"

MESON_ARGS=	-Dbuild-documentation=false \
		-Dbuild-examples=false

.include <bsd.port.mk>
