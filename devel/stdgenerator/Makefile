PORTNAME=	generator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1
CATEGORIES=	devel
PKGNAMEPREFIX=	std

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Reference implementation of std::generator proposal
WWW=		https://github.com/lewissbaker/generator

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++20-lang

INSTALL_TARGET=	install

USE_GITHUB=	yes
GH_ACCOUNT=	lewissbaker
GH_TAGNAME=	6ef0cca

PLIST_FILES=	include/__generator.hpp include/generator \
		lib/cmake/${PKGBASE}/${PKGBASE}-config-version.cmake \
		lib/cmake/${PKGBASE}/${PKGBASE}-config.cmake \
		lib/cmake/${PKGBASE}/${PKGBASE}-target.cmake

.include <bsd.port.mk>
