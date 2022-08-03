PORTNAME=	gitty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Smart terminal helper for git projects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	muesli

.include "${.CURDIR}/Makefile.deps"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
