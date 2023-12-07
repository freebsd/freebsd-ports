PORTNAME=	octosql
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.2
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OctoSQL is a query tool for databases, file formats, etc
WWW=		https://github.com/cube2222/octosql

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/cube2222/octosql

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
