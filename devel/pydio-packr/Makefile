PORTNAME=	packr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.30.2-0.20200608151212
DISTVERSIONSUFFIX=	-7d41389ccc6e
PORTREVISION=	4
CATEGORIES=	devel
PKGNAMEPREFIX=	pydio-

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Pydio fork of packr v1

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	www/pydio-cells doesn't build on i386, so there's no point building pydio-packr

USES=		go:modules

GO_MODULE=	github.com/pydio/packr
GO_TARGET=	./packr

PLIST_FILES=	bin/pydio-packr

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.mk>
