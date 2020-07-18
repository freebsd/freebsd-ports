# $FreeBSD$

PORTNAME=	vcglib
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Library for manipulation of triangle meshes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	cnr-isti-vclab
GH_TAGNAME=	f7871ee

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "apps eigenlib img vcg wrap" \
	 ${STAGEDIR}${PREFIX}/include/${PORTNAME})

.include <bsd.port.mk>
