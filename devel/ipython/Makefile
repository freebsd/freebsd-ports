# Created by: Dryice Liu
# $FreeBSD$

PORTNAME=	ipython
PORTVERSION=	0.13.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	An enhanced Interactive Python shell

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2:${PORTSDIR}/databases/py-sqlite3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>=2:${PORTSDIR}/misc/py-pexpect \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2:${PORTSDIR}/databases/py-sqlite3 \

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		ipcluster.1 ipcontroller.1 ipengine.1 iplogger.1 \
		ipython.1 irunner.1 pycolor.1

OPTIONS_DEFINE=	X11 HTML_NOTEBOOK ZMQ
OPTIONS_DEFAULT=X11 ZMQ

HTML_NOTEBOOK_DESC=	HTML notebook support
ZMQ_DESC=		ZMQ support (parallel computing, qt console, notebook)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=0:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:${PORTSDIR}/textproc/py-pygments
.endif

.if ${PORT_OPTIONS:MHTML_NOTEBOOK}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tornado>=2.0:${PORTSDIR}/www/py-tornado
.endif

.if ${PORT_OPTIONS:MZMQ}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.1.4:${PORTSDIR}/devel/py-pyzmq
.endif

post-patch:
.if ! ${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} -e "s# + example_files##g" ${WRKSRC}/setupbase.py
.endif

.include <bsd.port.mk>
