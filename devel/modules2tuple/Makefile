# $FreeBSD$

PORTNAME=	modules2tuple
PORTVERSION=	1.0.0
CATEGORIES=	devel

MAINTAINER=	dg@syrec.org
COMMENT=	Generate GH_TUPLE from modules.txt

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes

GH_TUPLE=	dmgk:${PORTNAME}:v${PORTVERSION}:DEFAULT

PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
