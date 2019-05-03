# $FreeBSD$

PORTNAME=	modules2tuple
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	dg@syrec.org
COMMENT=	Generate GH_TUPLE from modules.txt

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X main.version=${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	dmgk

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
