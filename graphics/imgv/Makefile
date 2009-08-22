# New ports collection makefile for:	imgv
# Date created:		2007-02-03
# Whom:			Simon Olofsson <simon@olofsson.de>
#
# $FreeBSD$
#

PORTNAME=	imgv
PORTVERSION=	3.1.5
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	simon@olofsson.de
COMMENT=	A unique and feature rich Image Viewer

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	2.2+
NO_BUILD=	yes

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},' ${WRKSRC}/gl.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/imgv.py ${PREFIX}/bin/imgv
	${RM} -f ${WRKSRC}/imgv.py ${WRKSRC}/setup.py
	${MKDIR} ${DATADIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/* ${DATADIR}/data
	${MKDIR} ${PYTHON_SITELIBDIR}/imgv/
	${TOUCH} ${PYTHON_SITELIBDIR}/imgv/__init__.py
	${INSTALL_DATA} ${WRKSRC}/*.py ${PYTHON_SITELIBDIR}/imgv/
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PYTHON_SITELIBDIR}/imgv/

.include <bsd.port.post.mk>
