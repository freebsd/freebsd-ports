PORTNAME=	coeurl
DISTVERSIONPREFIX=v
DISTVERSION=	0.1.0
CATEGORIES=	ftp www

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Simple async wrapper around CURL for C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	\
		libcurl.so:ftp/curl \
		libevent.so:devel/libevent \
		libspdlog.so:devel/spdlog

USES=		compiler:c++17-lang pkgconfig \
		meson tar:xz

USE_GITLAB=	yes
GL_SITE=	https://nheko.im/
GL_ACCOUNT=	nheko-reborn
GL_COMMIT=	a08f619adaa1ccd34eb6315d6578eddae0d1cc9b

.include <bsd.port.mk>
