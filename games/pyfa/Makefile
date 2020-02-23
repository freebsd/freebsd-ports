# Created by: Andrey Fesenko <andrey@bsdnir.info>
# $FreeBSD$

PORTNAME=	pyfa
PORTVERSION=	1.19.1
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	games python

MAINTAINER=	andrey@bsdnir.info
COMMENT=	Fitting tool for EVE Online

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0.6:databases/py-sqlalchemy10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:www/py-requests@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	pyfa-org
GH_PROJECT=	Pyfa

USES=		python:2.7 dos2unix
DOS2UNIX_GLOB=	*.py
NO_ARCH=	yes

PLIST_FILES=	bin/pyfa
PORTDATA=	*

USE_WX=		2.8 3.0
WX_COMPS=	wx:run python:run

OPTIONS_DEFINE=		DPSGRAPHING
DPSGRAPHING_DESC=	DPS graphing (requires NumPy and matplotlib)

DPSGRAPHING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=1.5.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools5>0:devel/py-more-itertools5@${PY_FLAVOR}

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

post-build:
	@${PRINTF} "#!/bin/sh\nexec ${PYTHON_CMD} ${DATADIR}/pyfa.py\n" \
		> ${WRKDIR}/pyfa.sh

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/pyfa.sh ${STAGEDIR}${PREFIX}/bin/pyfa

.include <bsd.port.mk>
