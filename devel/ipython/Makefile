# Created by: Dryice Liu
# $FreeBSD$

PORTNAME=	ipython
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	An enhanced Interactive Python shell

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2:${PORTSDIR}/databases/py-sqlite3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>=2:${PORTSDIR}/misc/py-pexpect \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

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
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tornado>=2.0:${PORTSDIR}/www/py-tornado \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:${PORTSDIR}/devel/py-Jinja2
.endif

.if ${PORT_OPTIONS:MZMQ} || ${PORT_OPTIONS:MHTML_NOTEBOOK}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.1.4:${PORTSDIR}/net/py-pyzmq
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
