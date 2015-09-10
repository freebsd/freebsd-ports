# Created by: Andrey Fesenko <andrey@bsdnir.info>
# $FreeBSD$

PORTNAME=	pyfa
PORTVERSION=	1.13.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games python

MAINTAINER=	andrey@bsdnir.info
COMMENT=	Fitting tool for EVE Online

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/gpl.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>0:${PORTSDIR}/databases/py-sqlalchemy

USE_GITHUB=	yes
GH_ACCOUNT=	DarkFenX

USES=		python:2 dos2unix
DOS2UNIX_GLOB=	*.py
WRKSRC=		${WRKDIR}/Pyfa-${PORTVERSION}

PLIST_FILES=	bin/pyfa
PORTDATA=	*

USE_WX=		2.8
WX_COMPS=	python:run
WX_UNICODE=	yes

OPTIONS_DEFINE=		DPSGRAPHING
DPSGRAPHING_DESC=	DPS graphing (requires NumPy and matplotlib. need fix)

DPSGRAPHING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}numpy>0:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}more-itertools>0:${PORTSDIR}/devel/py-more-itertools

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
