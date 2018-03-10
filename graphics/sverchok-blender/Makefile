# $FreeBSD$

PORTNAME=	sverchok
DISTVERSION=	0.5.9.6.2-452
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g4ec06b63
CATEGORIES=	graphics
PKGNAMESUFFIX=	-blender

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Add-on for Blender: parametric tool for architects and designers

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	blender:graphics/blender \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

.include "../blender/Makefile.versions"

USES=		python:${BLENDER_PY_VERSION}
USE_GITHUB=	yes
GH_ACCOUNT=	nortikin
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${RM} ${WRKSRC}/node_scripts/templates/polyvox  # stray link
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/blender/${BLENDER_BL_VERSION}/scripts/addons/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/blender/${BLENDER_BL_VERSION}/scripts/addons/${PORTNAME}
	# autoplist: it installs 800+ files into the plugins directory
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} share/blender/${BLENDER_BL_VERSION}/scripts/addons/${PORTNAME} -type f >> ${TMPPLIST} && \
		${FIND} -f share/blender/${BLENDER_BL_VERSION}/scripts/addons/${PORTNAME} -type d -empty | ${SED} -e 's/^/@dir /' >> ${TMPPLIST}

.include <bsd.port.mk>
