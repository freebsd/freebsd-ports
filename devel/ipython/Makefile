# Ports collection makefile for:	IPython
# Date created:				Nov, 13	2003
# Whom:					Dryice Liu
#
# $FreeBSD$
#

PORTNAME=	ipython
PORTVERSION=	0.10
CATEGORIES=	devel python
MASTER_SITES=	http://ipython.scipy.org/dist/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	An enhanced Interactive Python shell

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pexpect.py:${PORTSDIR}/misc/py-pexpect \
		${PYCTYPES}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=		ipython.1 pycolor.1 \
		ipcluster.1 ipcontroller.1 \
		ipengine.1 ipython-wx.1 \
		ipythonx.1 irunner.1
MANCOMPRESSED=	yes

.ifndef	NOPORTDOCS
PORTDOCS=	*
.endif

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e "s#('data',pjoin(docdirbase,'extensions'),igridhelpfiles),# #g" ${WRKSRC}/setupbase.py
	${REINPLACE_CMD} -e "s# + manual_files##g" ${WRKSRC}/setupbase.py
.endif

.if defined(NOPORTEXAMPLES)
	${REINPLACE_CMD} -e "s# + example_files##g" ${WRKSRC}/setupbase.py
.endif

.include <bsd.port.mk>
