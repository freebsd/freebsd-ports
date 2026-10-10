PORTNAME=	openbb
DISTVERSION=	5.0.0
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: Investment research for everyone, anywhere
WWW=		https://github.com/openbq-org/OpenBB

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}a2wsgi>0:www/py-a2wsgi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-bls>=2.0.0:finance/py-openbb-bls@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-cboe>=2.0.0:finance/py-openbb-cboe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-cftc>=2.0.0:finance/py-openbb-cftc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-charting>=4.0.0:finance/py-openbb-charting@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-commodity>=2.0.0:finance/py-openbb-commodity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-core>=2.0.1:finance/py-openbb-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-crypto>=2.0.0:finance/py-openbb-crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-currency>=2.0.0:finance/py-openbb-currency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-deribit>=2.0.0:finance/py-openbb-deribit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-derivatives>=2.0.0:finance/py-openbb-derivatives@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-ecb>=2.0.0:finance/py-openbb-ecb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-econometrics>=2.0.0:finance/py-openbb-econometrics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-economy>=2.0.0:finance/py-openbb-economy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-equity>=2.0.0:finance/py-openbb-equity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-etf>=2.0.0:finance/py-openbb-etf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-famafrench>=2.0.0:finance/py-openbb-famafrench@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-federal-reserve>=2.0.0:finance/py-openbb-federal-reserve@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-finra>=2.0.0:finance/py-openbb-finra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-fixedincome>=2.0.0:finance/py-openbb-fixedincome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-fred>=2.0.0:finance/py-openbb-fred@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-government-us>=2.0.0:finance/py-openbb-government-us@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-imf>=3.0.0:finance/py-openbb-imf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-index>=2.0.0:finance/py-openbb-index@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-mcp-server>=2.0.1:finance/py-openbb-mcp-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-nasdaq>=2.0.0:finance/py-openbb-nasdaq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-news>=2.0.0:finance/py-openbb-news@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-oecd>=2.0.0:finance/py-openbb-oecd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-platform-api>=2.0.1:finance/py-openbb-platform-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-quantitative>=2.0.0:finance/py-openbb-quantitative@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-sec>=2.0.0:finance/py-openbb-sec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-technical>=2.0.1:finance/py-openbb-technical@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-tmx>=2.0.0:finance/py-openbb-tmx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-us-eia>=2.0.0:finance/py-openbb-us-eia@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pywry>0:www/py-pywry@${PY_FLAVOR}
		# ${PYTHON_PKGNAMEPREFIX}openbb-cli>=2.0.1:finance/py-openbb-cli@${PY_FLAVOR} # missing
		# ${PYTHON_PKGNAMEPREFIX}openbb-devtools>=2.0.1:finance/py-openbb-devtools@${PY_FLAVOR} # missing
		# ${PYTHON_PKGNAMEPREFIX}openbb-jodi>=2.0.0:finance/py-openbb-jodi@${PY_FLAVOR} # missing

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

# finance/py-openbb-core owns the openbb/ namespace.  This metaport only
# pulls in the extension packages, so remove all staged Python files before
# packaging and clear the autoplist record so check-plist stays clean.
post-install: # see https://github.com/openbq-org/OpenBB/issues/7562
	@${RM} -r ${STAGEDIR}${PYTHONPREFIX_LIBDIR}
	@${ECHO_CMD} -n > ${_PYTHONPKGLIST}

.include <bsd.port.mk>
