PORTNAME=	financetoolkit
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.3
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Transparent and efficient financial analysis
WWW=		https://www.jeroenbouma.com/projects/financetoolkit \
		https://github.com/JerBouma/FinanceToolkit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.1:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=3.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-calamine>=0.3.0:textproc/py-python-calamine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.4:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.10:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=2.0:textproc/py-xlrd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yfinance>0:finance/py-yfinance@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}linearmodels>=6.0:math/py-linearmodels@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>=0.14:math/py-statsmodels@${PY_FLAVOR} # 2 optional deps required in tests
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arch>=7.0:science/py-arch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx2>=0.28:www/py-httpx2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=6.29:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=6.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-recording>=0.13.2:devel/py-pytest-recording@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR}
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fastmcp>=3.4.2:misc/py-fastmcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mcp>=1.27.0:misc/py-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>0:www/py-starlette@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	JerBouma
GH_PROJECT=	FinanceToolkit

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
# mcp 2.x in ports but tests need mcp 1.x; other deselected tests fail with the pandas/statsmodels versions in ports
TEST_ARGS=	--disable-plugin-autoload -p pytest_mock -p pytest_recording.plugin -p pytest_timeout \
		--ignore tests/mcp_server --ignore tests/test_input_validation.py \
		--ignore tests/econometrics \
		--deselect tests/discovery/test_discovery_model.py::test_the_earnings_calendar_splits_a_range_that_reaches_the_limit \
		--deselect tests/models/test_models_controller.py::test_get_ohlson_o_score \
		--deselect tests/models/test_models_controller.py::test_get_present_value_of_growth_opportunities \
		--deselect tests/models/test_models_controller.py::test_ohlson_o_score_compares_quarters_year_over_year \
		--deselect tests/options/test_options_controller.py::test_the_mcp_earnings_move_answers_every_ticker \
		--deselect tests/risk/test_market_liquidity_model.py::test_get_roll_spread_bid_ask_bounce \
		--deselect tests/risk/test_market_liquidity_model.py::test_get_roll_spread_positive_autocovariance \
		--deselect tests/test_helpers.py::test_enrich_historical_data_basic \
		--deselect tests/test_market_and_scenario_sources.py::test_implied_volatility_is_a_decimal_per_market_and_maturity \
		--deselect tests/test_toolkit_controller.py::test_supplied_statements_labelled_with_dates_keep_their_period_end \
		--deselect tests/test_toolkit_controller.py::test_supplied_historical_data_without_returns_gets_them_per_ticker

# tests as of 2.1.4: 612 passed, 58 skipped, 7 warnings in 31.38s
# tests as of 2.2.0: fail because they expect misc/py-mcp to be 1.x and ports have 2.x, otherwise likely nothing is wrong
# tests as of 2.2.1: --""--
# tests as of 2.3.3: 2745 passed, 207 skipped, 11 deselected, 3 xfailed, 3 xpassed, 64 warnings in 79.44s (0:01:19)

.include <bsd.port.mk>
