PORTNAME=	logfire-sdk
DISTVERSION=	5.4.0
CATEGORIES=	devel python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pydantic Logfire Python SDK
WWW=		https://pydantic.dev/logfire \
		https://github.com/pydantic/logfire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=2026.7.22:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}executing>=2.0.1:devel/py-executing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.39.0,<1.46.0:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp-proto-http>=1.39.0,<1.46.0:devel/py-opentelemetry-exporter-otlp-proto-http@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation>=0.41b0,<0.67b0:devel/py-opentelemetry-instrumentation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.39.0,<1.46.0:devel/py-opentelemetry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-semantic-conventions>=0.60b0,<0.67b0:devel/py-opentelemetry-semantic-conventions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.23.4:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.4.2:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.13.0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dirty-equals>0:devel/py-dirty-equals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inline-snapshot>0:devel/py-inline-snapshot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}loguru>0:devel/py-loguru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-handlebars>0:devel/py-pydantic-handlebars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-examples>0:devel/py-pytest-examples@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-vcr>0:devel/py-pytest-vcr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-mock>0:www/py-requests-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlmodel>0:databases/py-sqlmodel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}structlog>0:devel/py-structlog@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} TZ=UTC
TEST_ARGS=	--disable-plugin-autoload \
		-p anyio -p logfire -p pytest_logfire -p inline_snapshot \
		-p subtests -p timeout -p vcr \
		--ignore=tests/otel_integrations \
		--ignore=tests/auto_trace_samples \
		--ignore=tests/import_used_for_tests \
		--ignore=tests/test_agent_sandboxes.py \
		--ignore=tests/test_agent_setup_prompt.py \
		--ignore=tests/test_build_offline_skill_prompt.py \
		--ignore=tests/test_check_changelog_workflow.py \
		--ignore=tests/test_cli.py \
		--ignore=tests/test_configure.py \
		--ignore=tests/test_distribution_metadata.py \
		--ignore=tests/test_docs.py \
		--ignore=tests/test_docs_serve.py \
		--ignore=tests/test_gateway_skill.py \
		--ignore=tests/test_logfire_api.py \
		--ignore=tests/test_otel_logs.py \
		--ignore=tests/test_publish_firehose_template.py \
		--ignore=tests/test_query_client.py \
		--ignore=tests/test_query_client_errors.py \
		--ignore=tests/test_release_push.py \
		--ignore=tests/test_release_versioning.py \
		--ignore=tests/test_secret_scrubbing.py \
		-k 'not test_logfire_with_its_own_config and not test_span_started_while_suppressed_propagates_outer_span and not test_metrics_in_spans and not test_metrics_in_closed_span_context and not test_log_events and not test_log_events_with_kwargs and not test_api_requests_are_not_instrumented and not test_user_requests_are_still_instrumented'

# tests as of 5.4.0: 1536 passed, 23 skipped, 8 deselected, 2 xfailed, 10 warnings

NO_ARCH=	yes

.include <bsd.port.mk>
