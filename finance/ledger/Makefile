PORTNAME=	ledger
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.1
CATEGORIES=	finance

MAINTAINER=	woodycarey@hotmail.com
COMMENT=	John Wiegley's command line accounting program
WWW=		https://ledger-cli.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	utf8cpp>=0:devel/utf8cpp \
		icu>=63:devel/icu
LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		cmake compiler:c++17-lang cpe libedit perl5 shebangfix
CPE_VENDOR=	${PORTNAME}-cli
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_PERL5=	run
SHEBANG_FILES=	contrib/getquote-uk.py \
		contrib/ledger-du \
		contrib/non-profit-audit-reports/general-ledger-report.plx \
		contrib/non-profit-audit-reports/fund-report.plx \
		contrib/non-profit-audit-reports/csv2ods.py \
		contrib/non-profit-audit-reports/readcsv.py \
		contrib/non-profit-audit-reports/bank-reconcilation.plx \
		contrib/non-profit-audit-reports/unpaid-accruals-report.plx \
		contrib/non-profit-audit-reports/cash-receipts-and-disbursments-journals.plx \
		contrib/non-profit-audit-reports/summary-reports.plx \
		contrib/raw/GenerateLatexExpeneseReport.pl

OPTIONS_DEFINE=	GNUPG PYTHON
OPTIONS_SUB=	yes

GNUPG_LIB_DEPENDS=	libgpgme.so:security/gpgme \
			libgpgmepp.so:security/gpgmepp
GNUPG_CMAKE_BOOL=	USE_GPGME

PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-libs>0:devel/boost-python-libs@${PY_FLAVOR}
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-libs>0:devel/boost-python-libs@${PY_FLAVOR}
PYTHON_USES=		python
PYTHON_USES_OFF=	python:env
PYTHON_CMAKE_BOOL=	USE_PYTHON

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/share/contrib ${STAGEDIR}${DATADIR}
	${RM} ${STAGEDIR}${DATADIR}/repl.sh.orig
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${MV} ${STAGEDIR}${DATADIR}/ledger-completion.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d

post-stage-PYTHON-on:
	${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/ledger.so

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
