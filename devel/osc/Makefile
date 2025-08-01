PORTNAME=	osc
PORTVERSION=	1.19.0
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command Line Interface to work with an openSUSE Build Service
WWW=		https://en.opensuse.org/openSUSE:OSC \
		https://github.com/openSUSE/osc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/py-urllib3@${PY_FLAVOR}
TEST_DEPENDS=	git:devel/git \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0:devel/py-ruamel.yaml@${PY_FLAVOR}

USES=		cpe python
USE_GITHUB=	yes
GH_ACCOUNT=	openSUSE
USE_PYTHON=	autoplist cryptography distutils noflavors pytest
NO_ARCH=	yes
CPE_VENDOR=	suse
CPE_PRODUCT=	opensuse_osc

PORTDOCS=	*

PYTEST_BROKEN_TESTS=	testPrdiffDiffstat TestVC

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/osc.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_osc
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/contrib/osc.fish ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/osc.fish

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS README.md NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
