# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	pydbdesigner
PORTVERSION=	0.1.4.1
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Graphical designer for relational databases

LICENSE=	GPLv2

BROKEN=		Needs an unsupported version of wxWidgets

EXTRACT_AFTER_ARGS=	--exclude CVS

USE_PYTHON=	yes
USE_WX=		2.4
WX_COMPS=	python
REINPLACE_ARGS=	-i ""
WRKSRC=		${WRKDIR}/PyDBDesigner

NO_BUILD=	yes

MY_SITELIBDIR=		${PYTHON_SITELIBDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/env *python,${PYTHON_CMD},' \
		${WRKSRC}/main.py

do-install:
	${MKDIR} ${STAGEDIR}${MY_SITELIBDIR}
	cd ${WRKSRC};\
	${FIND} . | cut -c3- \
		| ${CPIO} -pdmv -R ${LIBOWN}:${LIBGRP} ${STAGEDIR}${MY_SITELIBDIR};\
	cd ${STAGEDIR}${MY_SITELIBDIR};\
	${FIND} . -type d | cut -c3- | ${XARGS} ${CHMOD} ${BINMODE};\
	${FIND} . -type f | cut -c3- | ${XARGS} ${CHMOD} ${LIBMODE};\
	${RM} -f ${STAGEDIR}${PREFIX}/bin/${PORTNAME};\
	${LN} -s ${STAGEDIR}${MY_SITELIBDIR}/main.py ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${CHMOD} ${BINMODE} ${STAGEDIR}${MY_SITELIBDIR}/main.py

.include <bsd.port.mk>
