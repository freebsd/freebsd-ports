# New ports collection makefile for:    ptkei
# Date created:                         26 October 1999
# Whom:                                 Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	ptkei
PORTVERSION=	000906
CATEGORIES=	games
MASTER_SITES=	ftp://www.empire.cx/pub/empire/clients/ \
		http://empire.idlpaper.com/~kevin/ptkei/download/

MAINTAINER=	darius@dons.net.au

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/Pmw/__init__.py:${PORTSDIR}/x11-toolkits/pmw

USE_PYTHON=	yes

do-build:
	@find ${WRKSRC} -name "*.pyc" | xargs ${RM}
	@find ${WRKSRC} \( -type f -or -type l \) | xargs ${CHMOD} 644
	@find ${WRKSRC} -type d | xargs ${CHMOD} 755
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC} 2>/dev/null

do-install:
	${MKDIR} ${PREFIX}/share/ptkei
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${PREFIX}/share/ptkei --unlink -xf -
	${SED} -e "s#%%PREFIX%%#${PREFIX}# ; s#%%PYTHON_CMD%%#${PYTHON_CMD}#" \
		${FILESDIR}/ptkei > ${WRKDIR}/ptkei.tmp
	${INSTALL_SCRIPT} ${WRKDIR}/ptkei.tmp ${PREFIX}/bin/ptkei

.include <bsd.port.mk>
