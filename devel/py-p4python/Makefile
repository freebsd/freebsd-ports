PORTNAME=	p4python
PORTVERSION=	2025.1.2767466
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antonfb@hesiod.org
COMMENT=	Python bindings for the Perforce API
WWW=		https://www.perforce.com/manuals/p4python/Content/P4Python/Home-p4python.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS+=	${LOCALBASE}/lib/perforce/libclient.a:devel/p4api
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		dos2unix python ssl
USE_PYTHON=	distutils autoplist
PYDISTUTILS_BUILDARGS=	--ssl ${OPENSSLLIB}

post-patch:
	@${REINPLACE_CMD} -e 's:%%LOCALBASE%%:${LOCALBASE}:' ${WRKSRC}/setup.py

.include <bsd.port.mk>
