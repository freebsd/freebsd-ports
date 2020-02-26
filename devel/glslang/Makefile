# $FreeBSD$

PORTNAME=	glslang
DISTVERSION=	7.11.3214
PORTREVISION=	1
CATEGORIES=	devel graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	24b3e8384e93.patch:-p1

MAINTAINER=	greg@unrelenting.technology
COMMENT=	OpenGL and OpenGL ES shader front end and validator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKDIR}/LICENSE

USES=		cmake compiler:c++11-lib

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup

post-extract:
	${SED} '/^$$/,$$d' ${WRKSRC}/${PORTNAME}/Include/Types.h \
			>${WRKDIR}/LICENSE

.include <bsd.port.mk>
