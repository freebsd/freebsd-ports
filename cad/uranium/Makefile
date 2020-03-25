# $FreeBSD$

PORTNAME=	Uranium
DISTVERSION=	15.06.03
CATEGORIES=	cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	Uranium is a Python framework for building 3D printing

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qt5-quick>0:x11-toolkits/py-qt5-quick@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		cmake python:3.4+ gettext
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
GH_TAGNAME=	8d2bada
STRIP=
NO_ARCH=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/uranium/scripts
	cd ${WRKSRC}/scripts && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/uranium/scripts

.include <bsd.port.mk>
