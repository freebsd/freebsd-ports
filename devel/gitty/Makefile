PORTNAME=	gitty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Smart terminal helper for git projects
WWW=		https://github.com/muesli/gitty

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/muesli/${PORTNAME}

.include "${.CURDIR}/Makefile.deps"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
