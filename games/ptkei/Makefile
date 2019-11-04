# Created by: Daniel O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	ptkei
PORTVERSION=	2.00.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/ptkei2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python/Tk graphical client for Wolfpack Empire servers

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/Pmw/__init__.py:x11-toolkits/py-Pmw@${PY_FLAVOR}

USES=		python:2.7 shebangfix
SHEBANG_FILES=	empire.py scripts/*.py

do-build:
	@${FIND} ${WRKSRC} -name "*.pyc" -delete
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC} 2>/dev/null

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${STAGEDIR}${DATADIR} --unlink -xf -
	${SED} -e "s#%%PREFIX%%#${PREFIX}# ; s#%%PYTHON_CMD%%#${PYTHON_CMD}#" \
		${FILESDIR}/ptkei > ${WRKDIR}/ptkei.tmp
	${INSTALL_SCRIPT} ${WRKDIR}/ptkei.tmp ${STAGEDIR}${PREFIX}/bin/ptkei

.include <bsd.port.mk>
