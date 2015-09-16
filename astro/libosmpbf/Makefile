# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libosmpbf
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	astro geography devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library for handling binary OpenStreetMap data

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.osmpbf

LIB_DEPENDS=	libprotobuf.so:${PORTSDIR}/devel/protobuf

USE_GITHUB=	yes
GH_ACCOUNT=	scrosby
GH_PROJECT=	OSM-binary

USES=		gmake
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

CXXFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
