# New ports collection makefile for:    ptkei
# Date created:                         26 October 1999
# Whom:                                 Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	ptkei
PORTVERSION=	1.18.1
CATEGORIES=	games
MASTER_SITES=	http://www.lfmm.org/ptkei/

MAINTAINER=	marcolz@stack.nl
COMMENT=	A Python/Tk graphical client for Wolfpack Empire servers

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/Pmw/__init__.py:${PORTSDIR}/x11-toolkits/pmw

USE_PYTHON=	yes

do-build:
	@${FIND} ${WRKSRC} -name "*.pyc" | ${XARGS} ${RM}
	@${FIND} ${WRKSRC} \( -type f -or -type l \) | ${XARGS} ${CHMOD} 644
	@${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} 755
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC} 2>/dev/null

do-install:
	${MKDIR} ${PREFIX}/share/ptkei
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${PREFIX}/share/ptkei --unlink -xf -
	${SED} -e "s#%%PREFIX%%#${PREFIX}# ; s#%%PYTHON_CMD%%#${PYTHON_CMD}#" \
		${FILESDIR}/ptkei > ${WRKDIR}/ptkei.tmp
	${INSTALL_SCRIPT} ${WRKDIR}/ptkei.tmp ${PREFIX}/bin/ptkei

.include <bsd.port.mk>
