# New ports collection makefile for:	pathological
# Date created:				15 Sept 2003
# Whom:					Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	pathological
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Pathological is an enriched clone of the game "Logical"

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes
NO_BUILD=	yes
MAN6=		pathological.6
MANCOMPRESSED=	yes

DOC_FILES=	favicon.ico index.html

do-install:
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}; tar -cf - circuits graphics music sounds pathological.ico pathological.py pathological.xpm) | \
		(cd ${DATADIR}; tar --unlink -xf -)
	@printf "#!/bin/sh\ncd ${DATADIR} && \
		exec ${PYTHON_CMD} ${DATADIR}/pathological.py\n" > ${WRKDIR}/pathological.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/pathological.sh ${PREFIX}/bin/pathological
.ifndef(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/${MAN6}.gz ${MAN6PREFIX}/man/man6/
.endif
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/html/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
