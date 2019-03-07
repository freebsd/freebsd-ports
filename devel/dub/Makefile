# $FreeBSD$

PORTNAME=	dub
PORTVERSION=	1.14.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Package and build manager for D applications and libraries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ldmd2:lang/ldc
LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	dlang

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${WRKSRC}/source/dub/version_.d

do-build:
	@cd ${WRKSRC} && ${SH} build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
