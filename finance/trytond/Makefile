# New ports collection makefile for:	trytond
# Date created:		09 July, 2009
# Whom:			Wen Heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	trytond
PORTVERSION=	2.4.1
CATEGORIES=	finance python
MASTER_SITES=	http://downloads2.tryton.org/2.4/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A three-tiers high-level general purpose application platform

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mx/__init__.py:${PORTSDIR}/lang/py-mx-base \
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}Genshi>0.5.1:${PORTSDIR}/textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}relatorio>=0.2.0:${PORTSDIR}/print/py-relatorio \
		${PYTHON_PKGNAMEPREFIX}polib>=0.7.0:${PORTSDIR}/devel/py-polib
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	WEBDAV OPENSSL PYDOT PYTZ
WEBDAV_DESC=	Add support for pywebdav
OPENSSL_DESC=	Add support for pyOpenSSL
PYDOT_DESC=	Add support for pydot
PYTZ_DESC=	Add support for pytz

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		PYEASYINSTALL_EGG=${PYEASYINSTALL_EGG}

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWEBDAV}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}PyWebDAV>=0:${PORTSDIR}/www/py-pywebdav
.endif

.if ${PORT_OPTIONS:MOPENSSL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl
.endif

.if ${PORT_OPTIONS:MPYDOT}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pydot>=0:${PORTSDIR}/graphics/py-pydot
.endif

.if ${PORT_OPTIONS:MPYTZ}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz
.endif

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
