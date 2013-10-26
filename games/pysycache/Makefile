# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	pysycache
PORTVERSION=	2.0
PORTREVISION=	6
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/py4childs/${PORTNAME}/v${PORTVERSION}/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Educational software made in python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_ZIP=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/datas.py ${WRKSRC}/datas.py \
		${WRKSRC}/datasclass.py ${WRKSRC}/pysybuttons.py ${WRKSRC}/pysyclick.py ${WRKSRC}/pysymove.py \
		${WRKSRC}/pysycache.py
	@${FIND} ${WRKSRC} -type d -name CVS -type d -print0 | ${XARGS} -0 ${RM} -R
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/pysycache.py ${PREFIX}/bin/pysycache.py
	@${RM} ${WRKSRC}/pysycache.py
.for DIRE in fonts help images sounds themes-buttons themes-click themes-move
	@${MKDIR} ${DATADIR}/${DIRE}
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/${DIRE}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/${DIRE}/{}" \;
.endfor
.for FILE in *.py *.pyc *.txt *.png
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DATADIR}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in AUTHORS ChangeLog NEWS README
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@cd ${WRKSRC}/doc/pysycache && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
