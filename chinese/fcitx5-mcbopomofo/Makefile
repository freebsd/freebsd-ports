PORTNAME=	fcitx5-mcbopomofo
DISTVERSION=	2.9.1
PORTREVISION=	1
CATEGORIES=	chinese textproc

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	McBopomofo for Fcitx5
WWW=		https://github.com/openvanilla/fcitx5-mcbopomofo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5 \
		libfmt.so:devel/libfmt \
		libicuuc.so:devel/icu \
		libjson-c.so:devel/json-c

USES=		cmake compiler:c++17-lang gettext-tools kde:5 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	openvanilla

USE_KDE=	ecm

CMAKE_OFF=	ENABLE_TEST

.include <bsd.port.mk>
