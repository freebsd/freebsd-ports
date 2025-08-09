PORTNAME=	coeurl
DISTVERSIONPREFIX=v
DISTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	ftp www

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Simple async wrapper around CURL for C++
WWW=		https://nheko.im/nheko-reborn/coeurl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libevent.so:devel/libevent \
		libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog

USES=		compiler:c++17-lang meson pkgconfig

USE_GITLAB=	yes
GL_SITE=	https://nheko.im/
GL_ACCOUNT=	nheko-reborn

.include <bsd.port.mk>
