# $FreeBSD$

PORTNAME=	vcglib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	devel

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Library for manipulation of triangle meshes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	cnr-isti-vclab

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "apps eigenlib img vcg wrap" \
	 ${STAGEDIR}${PREFIX}/include/${PORTNAME})

.include <bsd.port.mk>
