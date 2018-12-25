# $FreeBSD$

PORTNAME=	ignition-tools
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Ignition entry point (ign) for using all the suite of ignition tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang pkgconfig shebangfix
SHEBANG_FILES=	src/ign.in
USE_RUBY=	yes

BB_ACCOUNT=	ignitionrobotics
BB_PROJECT=	ign-tools
BB_COMMIT=	e775d6356667

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}
NO_ARCH=	yes

PLIST_FILES=	bin/ign \
		lib/cmake/ignition-tools/ignition-tools-config.cmake \
		libdata/pkgconfig/ignition-tools.pc

.include <bsd.port.mk>
