# Ports collection makefile for:	IPython
# Date created:				Nov, 13	2003
# Whom:					Dryice Liu
#
# $FreeBSD$
#

PORTNAME=	ipython
PORTVERSION=	0.13.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	An enhanced Interactive Python shell

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pexpect.py:${PORTSDIR}/misc/py-pexpect \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=2.1.4:${PORTSDIR}/devel/py-pyzmq

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		ipcluster.1 ipcontroller.1 ipengine.1 iplogger.1 \
		ipython.1 irunner.1 pycolor.1

OPTIONS_DEFINE=	X11 HTML_NOTEBOOK
OPTIONS_DEFAULT=X11

HTML_NOTEBOOK_DESC=	HTML notebook support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=0:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:${PORTSDIR}/textproc/py-pygments
.endif

.if ${PORT_OPTIONS:MHTML_NOTEBOOK}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tornado>=2.1:${PORTSDIR}/www/py-tornado
.endif

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
