PORTNAME=	dub
PORTVERSION=	1.40.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Package and build manager for D applications and libraries
WWW=		https://github.com/dlang/dub

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ldmd2:lang/ldc

USE_GITHUB=	yes
GH_ACCOUNT=	dlang

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@cd ${WRKSRC} && ${PREFIX}/bin/ldmd2 -run build.d

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
