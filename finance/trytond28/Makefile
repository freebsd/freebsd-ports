# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond
PORTVERSION=	2.8.13
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP \
		http://downloads.tryton.org/${PORTVERSION:R}/
PKGNAMESUFFIX=	28

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Server)

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mx/__init__.py:lang/py-mx-base \
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}Genshi>0.5.1:textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}relatorio>=0.6.0:print/py-relatorio \
		${PYTHON_PKGNAMEPREFIX}polib>=0.7.0:devel/py-polib \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:devel/py-dateutil
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	trytond-2.[46].*

USERS=		trytond
GROUPS=		trytond

OPTIONS_DEFINE=	WEBDAV PYOPENSSL PYDOT PYTZ
WEBDAV_DESC=	Add support for pywebdav
PYOPENSSL_DESC=	Add support for pyOpenSSL
PYDOT_DESC=	Add support for pydot
PYTZ_DESC=	Add support for pytz

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		PYTHON=${PYTHON_CMD}

PIDDIR?=	/var/run
LOGDIR?=	/var/log

USES=		python
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e 's|%%PIDDIR%%|${PIDDIR}|g' -e 's|%%LOGDIR%%|${LOGDIR}|g' \
		${WRKSRC}/etc/${PORTNAME}.conf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWEBDAV}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}PyWebDAV>=0:www/py-pywebdav
.endif

.if ${PORT_OPTIONS:MPYOPENSSL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl
.endif

.if ${PORT_OPTIONS:MPYDOT}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pydot>=0:graphics/py-pydot
.endif

.if ${PORT_OPTIONS:MPYTZ}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
