PORTNAME=	treefmt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	One CLI to format the code tree
WWW=		https://treefmt.com/ \
		https://github.com/numtide/treefmt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26,modules

USE_GITHUB=	yes
GH_ACCOUNT=	numtide

GO_MOD_DIST=	github # GO_MOD_DIST is used because GoLang servers reject it due to the emoji character(s) in the file names
GO_MODULE=	github.com/numtide/${PORTNAME}/v2

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
