# New ports collection makefile for:    ThudBoard
# Date created:         		04 Januar 2004
# Whom:                 		Jan Stocker <Jan.Stocker@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	thudboard
PORTVERSION=	1.8
CATEGORIES=	games
MASTER_SITES=	http://www.million.nl/file/

MAINTAINER=	lars.engels@0x20.net
COMMENT=	The Discworld Boardgame Board

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

NO_WRKSUBDIR=	yes
USE_PYTHON=	yes

do-configure:
	@${SED} -e "s#%%PREFIX%%#${PREFIX}# ; s#%%PYTHON_CMD%%#${PYTHON_CMD}#" \
		${FILESDIR}/thudboard > ${WRKDIR}/thudboard.tmp

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC} 2>/dev/null

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/thudboard.tmp ${PREFIX}/bin/thudboard
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.pyc ${DATADIR}
	@${TAR} -C ${WRKSRC} -cf - docs koomvalley img | \
		${TAR} -C ${DATADIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${DATADIR} -type d | ${XARGS} ${CHMOD} a+rx

.include <bsd.port.mk>
