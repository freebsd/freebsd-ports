PORTNAME=	coeurl
DISTVERSIONPREFIX=v
DISTVERSION=	0.3.0
PORTREVISION=	2
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

USES=		compiler:c++17-lang meson pkgconfig tar:xz

USE_GITLAB=	yes
GL_SITE=	https://nheko.im/
GL_ACCOUNT=	nheko-reborn
GL_TAGNAME=	2a20a129240a1a017b37b6874faab499ca4e523b

.include <bsd.port.mk>
