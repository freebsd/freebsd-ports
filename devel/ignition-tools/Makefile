PORTNAME=	ignition-tools
DISTVERSIONPREFIX=	ignition-tools_
DISTVERSION=	1.5.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Ignition entry point (ign) for using all the suite of ignition tools
WWW=		https://ignitionrobotics.org/home

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang pkgconfig ruby shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	src/ign.in

USE_GITHUB=	yes
GH_ACCOUNT=	gazebosim
GH_PROJECT=	gz-tools

PLIST_FILES=	bin/ign \
		lib/cmake/ignition-tools/ignition-tools-config.cmake \
		lib/libignition-tools-backward.so \
		libdata/pkgconfig/ignition-tools.pc \
		share/bash-completion/completions/ign \
		share/gz/gz1.completion

.include <bsd.port.mk>
