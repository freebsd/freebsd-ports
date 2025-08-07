PORTNAME=	imposm3
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.1
PORTREVISION=	17
CATEGORIES=	databases geography

MAINTAINER=	darcy@dbitech.ca
COMMENT=	Imposm imports OpenStreetMap data into PostGIS
WWW=		http://imposm.org/docs/imposm3/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgeos.so:graphics/geos \
		libleveldb.so:databases/leveldb

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.26.0:sys
GO_MODULE=	github.com/omniscale/imposm3
GO_TARGET=	./cmd/imposm
GO_BUILDFLAGS=	-ldflags "\
		-X github.com/omniscale/imposm3.Version=${DISTVERSION}"

PLIST_FILES=	bin/imposm

PORTEXAMPLES=	example-mapping.json example-mapping.yml
OPTIONS_DEFINE=	EXAMPLES

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
