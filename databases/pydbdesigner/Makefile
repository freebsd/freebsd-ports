# New ports collection makefile for:	pydbdesigner
# Date created:		2003-01-02
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	pydbdesigner
PORTVERSION=	0.1.4.1
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Graphical designer for relational databases

EXTRACT_AFTER_ARGS=	| ${TAR} --exclude CVS -xf -

USE_PYTHON=	2.2+
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
	${MKDIR} ${MY_SITELIBDIR}
	cd ${WRKSRC};\
	${FIND} . | cut -c3- \
		| ${CPIO} -pdmv -R ${LIBOWN}:${LIBGRP} ${MY_SITELIBDIR};\
	cd ${MY_SITELIBDIR};\
	${FIND} . -type d | cut -c3- | ${XARGS} ${CHMOD} ${BINMODE};\
	${FIND} . -type f | cut -c3- | ${XARGS} ${CHMOD} ${LIBMODE};\
	${RM} -f ${PREFIX}/bin/${PORTNAME};\
	${LN} -s ${MY_SITELIBDIR}/main.py ${PREFIX}/bin/${PORTNAME}
	${CHMOD} ${BINMODE} ${MY_SITELIBDIR}/main.py

.include <bsd.port.mk>
