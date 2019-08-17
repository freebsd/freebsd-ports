# $FreeBSD$

PORTNAME=	cointop
PORTVERSION=	1.1.2
CATEGORIES=	finance

MAINTAINER=	ndowens@yahoo.com
COMMENT=	Light cryptocurrency coin stats

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	miguelmota

GO_BUILDFLAGS=	-ldflags="-X main.Version=${DISTVERSION}"

PLIST_FILES=	bin/cointop

.include <bsd.port.mk>
