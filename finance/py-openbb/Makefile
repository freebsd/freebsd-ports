PORTNAME=	openbb
DISTVERSION=	4.7.2
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: Investment research for everyone, anywhere
WWW=		https://github.com/OpenBB-finance/OpenBB

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openbb-benzinga>=1.6.1:finance/py-openbb-benzinga@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-bls>=1.3.1:finance/py-openbb-bls@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-cftc>=1.4.1:finance/py-openbb-cftc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-commodity>=1.5.2:finance/py-openbb-commodity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-congress-gov>=1.2.3:finance/py-openbb-congress-gov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-core>=1.6.10:finance/py-openbb-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-crypto>=1.6.2:finance/py-openbb-crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-currency>=1.6.2:finance/py-openbb-currency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-derivatives>=1.6.2:finance/py-openbb-derivatives@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-econdb>=1.5.1:finance/py-openbb-econdb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-economy>=1.6.2:finance/py-openbb-economy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-equity>=1.6.2:finance/py-openbb-equity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-etf>=1.6.2:finance/py-openbb-etf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-federal-reserve>=1.6.2:finance/py-openbb-federal-reserve@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-fixedincome>=1.6.2:finance/py-openbb-fixedincome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-fmp>=1.6.1:finance/py-openbb-fmp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-fred>=1.6.1:finance/py-openbb-fred@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-government-us>=1.6.1:finance/py-openbb-government-us@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-imf>=2.1.3:finance/py-openbb-imf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-index>=1.6.2:finance/py-openbb-index@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-intrinio>=1.6.1:finance/py-openbb-intrinio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-news>=1.6.2:finance/py-openbb-news@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-oecd>=1.6.1:finance/py-openbb-oecd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-platform-api>=1.3.6:finance/py-openbb-platform-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-regulators>=1.6.2:finance/py-openbb-regulators@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-sec>=1.6.1:finance/py-openbb-sec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-tiingo>=1.6.1:finance/py-openbb-tiingo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-tradingeconomics>=1.6.1:finance/py-openbb-tradingeconomics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-us-eia>=1.3.1:finance/py-openbb-us-eia@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-yfinance>=1.6.3:finance/py-openbb-yfinance@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openbb-alpha-vantage>=1.6.1:finance/py-openbb-alpha-vantage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-biztoc>=1.6.1:finance/py-openbb-biztoc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-cboe>=1.6.1:finance/py-openbb-cboe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-charting>=3.0.0:finance/py-openbb-charting@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-deribit>=1.2.1:finance/py-openbb-deribit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-ecb>=1.6.1:finance/py-openbb-ecb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-econometrics>=1.7.2:finance/py-openbb-econometrics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-famafrench>=1.2.1:finance/py-openbb-famafrench@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-finra>=1.6.1:finance/py-openbb-finra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-finviz>=1.5.1:finance/py-openbb-finviz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-mcp-server>=1.4.1:finance/py-openbb-mcp-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-multpl>=1.3.1:finance/py-openbb-multpl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-nasdaq>=1.6.2:finance/py-openbb-nasdaq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-quantitative>=1.6.2:finance/py-openbb-quantitative@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-seeking-alpha>=1.6.1:finance/py-openbb-seeking-alpha@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-stockgrid>=1.6.1:finance/py-openbb-stockgrid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-technical>=1.6.2:finance/py-openbb-technical@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-tmx>=1.5.2:finance/py-openbb-tmx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-tradier>=1.5.1:finance/py-openbb-tradier@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-wsj>=1.6.1:finance/py-openbb-wsj@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

# finance/py-openbb-core owns the openbb/ namespace.  This metaport only
# pulls in the extension packages, so remove all staged Python files before
# packaging and clear the autoplist record so check-plist stays clean.
post-install: # see https://github.com/OpenBB-finance/OpenBB/issues/7562
	@${RM} -r ${STAGEDIR}${PYTHONPREFIX_LIBDIR}
	@${ECHO_CMD} -n > ${_PYTHONPKGLIST}

.include <bsd.port.mk>
