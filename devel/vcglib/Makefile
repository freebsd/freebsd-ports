# $FreeBSD$

PORTNAME=	vcglib
PORTVERSION=	2020.09
CATEGORIES=	devel

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Library for manipulation of triangle meshes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${LOCALBASE}/include/exif.h:devel/easyexif

USE_GITHUB=	yes
GH_ACCOUNT=	cnr-isti-vclab

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "apps eigenlib img vcg wrap" \
	 ${STAGEDIR}${PREFIX}/include/${PORTNAME})

.include <bsd.port.mk>
