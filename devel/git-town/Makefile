PORTNAME=	git-town
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.1
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Git extension for generic, high-level git workflow support
WWW=		https://www.git-town.com

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/git-town/git-town/v9

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
