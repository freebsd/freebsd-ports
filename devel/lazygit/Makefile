# $FreeBSD$

PORTNAME=	lazygit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	devel

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Simple terminal UI for git commands

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	jesseduffield

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
