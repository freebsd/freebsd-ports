# New ports collection makefile for:    ThudBoard
# Date created:         		04 Januar 2004
# Whom:                 		Jan Stocker <Jan.Stocker@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	thudboard
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.million.nl/file/

MAINTAINER=	Jan.Stocker@t-online.de
COMMENT=	The Discworld Boardgame Board

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-configure:
	@${SED} -e "s#%%PREFIX%%#${PREFIX}# ; s#%%PYTHON_CMD%%#${PYTHON_CMD}#" \
		${FILESDIR}/thudboard > ${WRKDIR}/thudboard.tmp

do-build:
	@${FIND} ${WRKSRC} -name "*.pyc" | ${XARGS} ${RM}
	@${FIND} ${WRKSRC} \( -type f -or -type l \) | ${XARGS} ${CHMOD} 644
	@${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} 755
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC} 2>/dev/null

do-install:
	@${MKDIR} ${DATADIR}
	@${TAR} -C ${WRKSRC} --exclude="*.py.orig" --exclude="docs*" -cf - . | ${TAR} -C ${DATADIR} --unlink -xf -
	@${INSTALL_SCRIPT} ${WRKDIR}/thudboard.tmp ${PREFIX}/bin/thudboard
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${TAR} -C ${WRKSRC}/docs/ -cf - . | ${TAR} -C ${DOCSDIR} --unlink -xf -
.endif
.include <bsd.port.mk>
