# New ports collection makefile for:	trytond
# Date created:		09 July, 2009
# Whom:			Wen Heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	trytond
PORTVERSION=	1.4.3
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/1.4/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A three-tiers high-level general purpose application platform

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mx/__init__.py:${PORTSDIR}/lang/py-mx-base \
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}Genshi>0.5.1:${PORTSDIR}/textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}relatorio>=0.2.0:${PORTSDIR}/print/py-relatorio
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

OPTIONS=	WEBDAV   "Add support for pywebdav" Off \
		OPENSSL  "Add support for pyOpenSSL" Off \
		PYDOT    "Add support for pydot" Off \
		PYTZ    "Add support for pytz" Off

.include <bsd.port.pre.mk>

.if defined(WITH_WEBDAV)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}PyWebDAV>=0:${PORTSDIR}/www/py-pywebdav
.endif

.if defined(WITH_OPENSSL)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl
.endif

.if defined(WITH_PYDOT)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pydot>=0:${PORTSDIR}/graphics/py-pydot
.endif

.if defined(WITH_PYTZ)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz
.endif

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		PYEASYINSTALL_EGG=${PYEASYINSTALL_EGG}

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
