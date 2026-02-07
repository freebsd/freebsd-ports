PORTNAME=	sord
DISTVERSION=	0.16.20
CATEGORIES=	devel
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Lightweight C library for storing RDF data in memory
WWW=		https://drobilla.net/category/sord/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libserd-0.so:devel/serd \
		libzix-0.so:devel/zix

USES=		meson pkgconfig python:build tar:xz
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddocs=disabled \
		--mandir=${PREFIX}/share/man
PLIST_SUB=	VERSION=${DISTVERSION}

.include <bsd.port.mk>
