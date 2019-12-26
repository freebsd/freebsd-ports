# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	pysycache
PORTVERSION=	2.0
PORTREVISION=	12
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/py4childs/${PORTNAME}/v${PORTVERSION}/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Educational software made in python

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYGAME}

USES=		python:2.7 shebangfix zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message
SHEBANG_FILES=	*.py

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/datas.py ${WRKSRC}/datas.py \
		${WRKSRC}/datasclass.py ${WRKSRC}/pysybuttons.py ${WRKSRC}/pysyclick.py ${WRKSRC}/pysymove.py \
		${WRKSRC}/pysycache.py
	@${FIND} ${WRKSRC} -type d -name CVS -print0 | ${XARGS} -0 ${RM} -R
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pysycache.py ${STAGEDIR}${PREFIX}/bin/pysycache.py
	@${RM} ${WRKSRC}/pysycache.py
	cd ${WRKSRC} && ${COPYTREE_SHARE} " \
			fonts help images sounds themes-buttons themes-click themes-move \
			*.py *.pyc *.txt *.png \
		" ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog NEWS README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/pysycache && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
