PORTNAME=	nokap
PORTVERSION=	0.2.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Capture screenshots and PDFs from web pages with headless Chrome
WWW=		https://github.com/posit-dev/nokap

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=45:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=12.0:devel/py-websockets@${PY_FLAVOR} \
		chrome:www/chromium

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ARGS=	-k "not test_find_chrome_env_var and not test_find_chrome_headless_shell_on_path and not test_find_chrome_picks_newest_installed_version and not test_find_chrome_prefers_installed_headless_shell and not test_capture_recovers_and_removes_dead_browser_profile"

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|os.environ.get("CHROME_PATH")|"${LOCALBASE}/bin/chrome"|' ${WRKSRC}/nokap/_browser.py

# tests as of 0.2.0: 186 passed, 3 skipped, 7 deselected

.include <bsd.port.mk>
