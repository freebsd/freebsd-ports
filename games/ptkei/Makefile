# Created by: Daniel O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	ptkei
PORTVERSION=	2.00.0
CATEGORIES=	games
MASTER_SITES=	SF/ptkei2

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Python/Tk graphical client for Wolfpack Empire servers

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/Pmw/__init__.py:x11-toolkits/py-Pmw

USES=		python

do-build:
	@${FIND} ${WRKSRC} -name "*.pyc" -delete
	@${FIND} ${WRKSRC} \( -type f -or -type l \) | ${XARGS} ${CHMOD} 644
	@${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} 755
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC} 2>/dev/null

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${STAGEDIR}${DATADIR} --unlink -xf -
	${SED} -e "s#%%PREFIX%%#${PREFIX}# ; s#%%PYTHON_CMD%%#${PYTHON_CMD}#" \
		${FILESDIR}/ptkei > ${WRKDIR}/ptkei.tmp
	${INSTALL_SCRIPT} ${WRKDIR}/ptkei.tmp ${STAGEDIR}${PREFIX}/bin/ptkei

.include <bsd.port.mk>
