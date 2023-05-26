PORTNAME=	osc
PORTVERSION=	1.1.4
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command Line Interface to work with an openSUSE Build Service
WWW=		https://en.opensuse.org/openSUSE:OSC \
		https://github.com/openSUSE/osc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/py-urllib3@${PY_FLAVOR}

USES=		cpe python
USE_GITHUB=	yes
GH_ACCOUNT=	openSUSE
USE_PYTHON=	autoplist distutils noflavors pytest
NO_ARCH=	yes
CPE_VENDOR=	suse
CPE_PRODUCT=	opensuse_osc

PORTDOCS=	*

PYTEST_BROKEN_TESTS=	testPrdiffDiffstat

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS README.md NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
